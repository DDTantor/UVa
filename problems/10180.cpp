#include <iostream>
#include <cmath>
#include <iomanip>
#include <tuple>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator>>(istream& in, point& p)
    {
        return in >> p.x >> p.y;
    }
}p1, p2, o(0, 0);

double dist(point p1, point p2)
{
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dot(point p, point q)
{
    return p.x * q.x + p.y * q.y;
}

double DistToSeg(point A, point B, point p)
{
    point r, M = p;
    M.x -= A.x, M.y -= A.y;
    B.x -= A.x, B.y -= A.y;
    double lambda = max(0.0, min(dot(M, B) / dot(B, B), 1.0));
    r.x = lambda * B.x + A.x;
    r.y = lambda * B.y + A.y;
    return dist(r, p);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    double r;
    cin >> t;
    cout << fixed << setprecision(3);
    while (cin >> p1 >> p2 >> r, t--)
    {
        double d1 = dist(p1, p2);
        if (DistToSeg(p1, p2, o) +eps > r)
            cout << d1 << '\n';
        else
        {
            double d2 = dist(p1, o);
            double d3 = dist(p2, o);
            double res = sqrt(d2 * d2 - r * r) + sqrt(d3 * d3 - r * r);
            double angle = acos((d2 * d2 + d3 * d3 - d1 * d1)/ (2 * d2 * d3));
            angle = angle - acos(r / d2) - acos(r / d3);
            cout << r * angle + res << '\n';
        }
    }   
}
