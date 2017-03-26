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
    friend istream& operator >> (istream& in, point& p) {return in >> p.x >> p.y;}
    bool operator < (point& b) const {return x < b.x || (x == b.x && y < b.y);}
};

double cross (point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double Area(vector<point>& P)
{
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        double x1 = P[i].x, x2 = P[i + 1].x;
        double y1 = P[i].y, y2 = P[i + 1].y;
        A += x1 * y2 - x2 * y1;
    }
    return 0.5 * fabs(A);
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());
    vector<point> H(2 * n);
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

int main()
{
    int n, t = 1;
    while (cin >> n, n)
    {
        cout << "Tile #" << t++ << '\n';
        vector<point> P(n + 1);
        double A, A1;
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        P[n] = P[0];
        A1 = Area(P);
        P = ConvexHull(P);
        A = Area(P);
        cout << fixed << setprecision(2) << "Wasted Space = " << (A - A1) / A * 100 << " %\n\n";
    }
}
