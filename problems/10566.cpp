#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define eps 1e-6

double x, y, c;

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
};

//p(0, 0), q(w, hx), A(0, hy), B(w, 0);

point lineIntersectSeg(point p, point q, point A, point B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

int main()
{
    while (cin >> x >> y >> c)
    {
        double lo = eps, hi = min(x, y);
        while (fabs(lo - hi) > eps)
        {
            double w = (lo + hi) / 2.0, hx = sqrt(x * x - w * w), hy = sqrt(y * y - w * w);
            point res = lineIntersectSeg(point(0, 0), point(w, hx), point(0, hy), point(w, 0));
            (c > res.y? hi : lo) = w;
        }

        cout << fixed << setprecision(3) << lo << '\n';
    }
}
