#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& p) {return in >> p.x >> p.y;}
    point operator -(point a) {return point(x - a.x, y - a.y);}
};

double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double snorm(point a)
{
    return a.x * a.x + a.y * a.y;
}

double angle(point a, point o, point b)
{
    return acos(dot(a - o, b - o) / sqrt(snorm(a - o) * snorm(b - o)));
}

bool ccw(point p, point q, point r)
{
    return cross(p - q, p - r) > 0;
}
bool inPolygon(point p, const vector<point>& P)
{
    double sum = 0, n = P.size();
    for (int i = 0; i < P.size() - 1; ++i)
    {
        if (ccw(p, P[i], P[i + 1]))
            sum += angle(P[i], p, P[i + 1]);
        else
            sum -= angle(P[i], p, P[i + 1]);
    }
    return fabs(fabs(sum) - 2 * M_PI) < eps;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        point pt;
        vector<point> P(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        P[n] = P[0];
        cin >> pt;
        if (inPolygon(pt, P))
            cout << "T\n";
        else
            cout << "F\n";
    }
}
