#include <iostream>
#include <vector>
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
};
    
double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(point a,  point b)
{
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p,  point q,  point r)
{
    return cross(p - q, p - r) > 0;
}

double snorm(point a)
{
    return a.x * a.x + a.y * a.y;
}

double angle(point a, point o, point b)
{
    return acos(dot(a - o, b - o) / sqrt(snorm(a - o) * snorm(b - o)));
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

bool InPolygon(point p, const vector<point>& P)
{
    double sum = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        if (ccw(p, P[i], P[i + 1]))
            sum += angle(P[i], p, P[i + 1]);
        else
            sum -= angle(P[i], p, P[i + 1]);
    }
    return fabs(fabs(sum) - 2 * M_PI) < eps;
}

double Area(const vector<point>& P)
{
    double sum = 0, x1, x2, y1, y2;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        x1 = P[i].x; x2 = P[i + 1].x;
        y1 = P[i].y; y2 = P[i + 1].y;
        sum += (x1 * y2 - x2 * y1);
    }
    return fabs(sum) / 2.0;
}

int main()
{
    vector<vector<point> > K;
    int n;
    while (cin >> n, n != -1)
    {
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        K.push_back(CH(P));
    }
    
    point R;
    double A = 0;
    while (cin >> R)
        for (int i = 0; i < K.size(); ++i)
            if (InPolygon(R, K[i]))
                A += Area(K[i]), K.erase(K.begin() + i);

    cout << fixed << setprecision(2) << A << '\n';
    
}
