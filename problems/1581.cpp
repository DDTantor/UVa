#include <cstring>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

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
};

double cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double dot(point p, point q)
{
    return p.x * q.x + p.y * q.y;
}

double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

double angle(point a, point o, point b)
{
    point a_p = point(a.x - o.x, a.y - o.y), b_p = point(b.x - o.x, b.y - o.y);
    return acos(dot(a_p, b_p) / sqrt(dot(a_p, a_p) * dot(b_p, b_p)));
}

double Area(vector<point>& P)
{
    if (P.size() < 3)
        return 0;
    
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
        A += cross(P[i], point(0, 0), P[i + 1]);
    
    return 0.5 * abs(A);
}

double Area(point a, point b, point c)
{
    double A = dist(a, b);
    double B = dist(b, c);
    double C = dist(c, a);
    double S = (A + B + C) * 0.5;
    return sqrt(S * (S - A) * (S - B) * (S - C));
}

bool In(point p, double r)
{
    return dot(p, p) < r * r + eps;
}

point BSearch(point p, point q, double r)
{
    while (abs(p.x - q.x) > eps || abs(p.y - q.y) > eps)
    {
        point m(0.5 * (p.x + q.x), 0.5 * (p.y + q.y));
        (In(m, r)? p : q) = m;
    }

    return p;
}

double DistToSeg(point A, point B, point p, point& r)
{
    point M = p;
    M.x -= A.x, M.y -= A.y;
    B.x -= A.x, B.y -= A.y;
    double lambda = max(0.0, min(dot(M, B) / dot(B, B), 1.0));
    r.x = lambda * B.x + A.x;
    r.y = lambda * B.y + A.y;
    return hypot(r.x - p.x, r.y - p.y);
}

double CircSeg(point a, point b, double r)
{
    return r * r / 2 * (angle(a, point(0, 0), b) - sin(angle(a, point(0, 0),  b)));
}

double CircTri(point a, point b, double r)
{
    bool t1 = In(a, r), t2 = In(b, r);
    double S = Area(a, b, point(0, 0));
    point h;
    if (t1 && t2)
        return S;
    else if (t1 || t2)
    {
        if (t2) swap(a, b);
        point p = BSearch(a, b, r), q = BSearch(point(0, 0), b, r);
        return S - Area(p, q, b) + CircSeg(p, q, r);
    }
    else if (DistToSeg(a, b, point(0, 0), h) < r + eps)
    {
        point p1 = BSearch(h, a, r);
        point p2 = BSearch(point(0, 0), a, r);
        point q1 = BSearch(h, b, r);
        point q2 = BSearch(point(0, 0), b, r);
        return S - Area(p1, p2, a) + CircSeg(p1, p2, r)-
            Area(q1, q2, b) + CircSeg(q1, q2, r);
    }

    return 0.5 * r * r * angle(a, point(0, 0), b);
}

int main()
{
    int n;
    double r;
    while (cin >> n >> r)
    {
        vector<point> P(n + 1);
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        P[n] = P[0];
        double res = 0;
        for (int i = 0; i < P.size() - 1; ++i)
            res += (cross(point(0, 0), P[i], P[i + 1]) > -eps? -1 : 1) * CircTri(P[i], P[i + 1], r);

        cout << fixed << setprecision(9) << res << '\n';
    }
}
