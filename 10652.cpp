#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    bool operator <(point& p) {return x < p.x || (x == p.x && y < p.y);}
};

double cross(point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    vector<point> H(2 * n);
    
    sort(P.begin(), P.end());
    
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    
    H.resize(k);
    return H;
}

double Area(vector<point>& P)
{
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        double x1 = P[i].x, x2 = P[i + 1].x;
        double y1 = P[i].y, y2 = P[i + 1].y;
        A += (x1 * y2 - x2 * y1);
    }
    return fabs(A) * 0.5;
}

int main()
{
    int n, t;
    cin >> t;
    while (cin >> n, t--)
    {
        double A1 = 0, A;
        int m = 0;
        vector<point> P(4 * n);
        for (int i = 0; i < n; ++i)
        {
            double h, w, theta, x, y, l, k;
            cin >> x >> y >> w >> h >> theta;
            theta *= M_PI / 180.0;
            A1 += h * w;
            l = hypot(h, w) / 2;
            
            k = M_PI - (theta + atan(w / h));
            P[m].x = x - l * sin(k), P[m].y = y + l * cos(k), m++;
            P[m].x = 2 * x - P[m - 1].x, P[m].y = 2 * y - P[m - 1].y, m++;
            
            k = atan(h / w) * 2 + M_PI / 2 - k;
            P[m].x = x - l * cos(k), P[m].y = y + l * sin(k), m++;
            P[m].x = 2 * x - P[m - 1].x, P[m].y = 2 * y - P[m - 1].y, m++;
        }
        P = ConvexHull(P);
        A = Area(P);
        cout << fixed << setprecision(1) << 100 * A1 / A << " %\n";
    }
}
