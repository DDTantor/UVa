#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& a) {return in >> a.x >> a.y;}
    bool operator < (point& b) const {return x < b.x || (x == b.x && y < b.y);}
};

double dist(point& p, point& q, point& a)
{
    double A = q.y - p.y;
    double B = q.x - p.x;
    double C = p.y * q.x - p.x * q.y;
    return fabs(A * a.x - B * a.y + C) / hypot(A, B);
}

double cross(point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> ConvexHull(vector<point>& P)
{
    sort(P.begin(), P.end());
    vector<point> H;
    for (int i = 0; i < 2; ++i)
    {
        int s = H.size();
        for (point p : P)
        {
            while (H.size() >= s + 2 && cross(H[H.size() - 2], H[H.size() - 1], p) < 0)
                H.pop_back();
            
            H.push_back(p);
        }
        
        if (!i) H.pop_back();
        reverse(P.begin(), P.end());
    }
    
    return H;
}

int main()
{
    int n, c = 1;
    while (cin >> n, n)
    {
        cout << "Case " << c++ << ": ";
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        
        P = ConvexHull(P);
        double m = INT_MAX, M;
        
        for (int i = 0; i < P.size() - 1; ++i)
        {
            M = 0.0;
            for (int j = 0; j < P.size(); ++j)
                M = max(M, dist(P[i], P[i + 1], P[j]));
            
            m = min(m, M);
        }
        cout << fixed << setprecision(2) << m  << '\n'; 
    }
}
