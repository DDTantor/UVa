#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define eps 1e-9

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator>>(istream& in, point& p){return in >> p.x >> p.y;}
}P[6];

double cross(point& a, point& o, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

point f(double a)
{
    return point(a * (P[2].x - P[0].x) + P[0].x, a * (P[2].y - P[0].y) + P[0].y);
}

double g(double a)
{
    return round(1000.0 * a) / 1000.0;
}

point g(point p)
{
    return point(g(p.x), g(p.y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(3);
    while (cin >> P[0])
    {
        bool fl = (P[0].x == 0 && P[0].y == 0);
        for (int i = 1; i < 6; ++i)
            cin >> P[i], fl &= (P[i].x == 0 && P[i].y == 0);

        if (fl)
            return 0;
        
        double A = 0.5 * abs(cross(P[3], P[4], P[5]));

        double lo = 0, hi = 10000;
        while (abs(lo - hi) >= eps)
        {

            double mid = 0.5 * (lo + hi);
            point p = f(mid);
            (abs(cross(p, P[0], P[1])) < A ? lo : hi) = mid;
        }

        point p = f(lo);
        point q = point(g(P[1].x + p.x - P[0].x), g(P[1].y + p.y - P[0].y));
        p = g(p);
        cout << q.x << ' ' << q.y << ' ' << p.x << ' ' << p.y << '\n';
    }
}
