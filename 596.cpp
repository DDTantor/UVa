#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point () {}
    point(double x, double y) : x(x), y(y) {}
    point operator- (point p) {return point(x - p.x, y - p.y);}
    friend istream& operator >>(istream& in, point& p){return in >> p.x >> p.y;}
    bool operator == (point p) {return x == p.x && y == p.y;}
};
    
double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

double cross(point a,  point b)
{
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p,  point q,  point r)
{
    if (p == q || q == r)
        return false;
    return cross(p - q, p - r) >= 0;
}


bool collinear(point p,  point q,  point r)
{
    return fabs(cross(q - p, r - p)) < eps;
}

point pivot(0, 0);

bool angleCmp(point a,  point b)
{
    if (collinear(pivot, a, b))
        return dist(pivot, a) < dist(pivot, b);
    
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
}

bool cmp(point a, point b)
{
    return a.x > b.x || (a.x == b.x && a.y < b.y);
}

vector<point> CH(vector<point>& P)
{
    int i, j, n = P.size();
    int P0 = 0;
    for (i = 1; i < n; ++i)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
            
    point tmp = P[0]; P[0] = P[P0]; P[P0] = tmp;
    
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    
    vector<point> S;
    S.push_back(P[n - 1]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2;
    while (i < n)
    {
        j = S.size() - 1;
        if (ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]);
        else S.pop_back();
    }
    return S;
}


int main()
{
    vector<point> P;
    point p;
    char c;
    string s, s1;
    int n, t = 1;
    while (cin.ignore(2), getline(cin, s), s != "D")
    {
        cout << s << " convex hull:\n"; 
        
        while (cin.peek() != 'S' && cin.peek() != 'E')
        {
            getline(cin, s);
            istringstream iss(s);
            iss >> c >> n;
            for (int i = 0; i < n; ++i)
            {
                iss >> p;
                P.push_back(p);
            }
        }
        P = CH(P);
        int ind = 0;
        point best(-1001, 1001);
        for (int i = 0; i < P.size() - 1; ++i)
            if (cmp(P[i], best))
                best = P[i], ind = i;
        
        int k = P.size() - 1;
        for (int i = 0; i < P.size() - 1; ++i)
            cout << " (" << P[(ind + i) % k].x << ',' << P[(ind + i) % k].y << ")";

        cout << '\n';
        P.clear();
    } 
    
}
