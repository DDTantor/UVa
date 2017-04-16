#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

#define eps 1e-9

struct point
{
    double x, y;
    point(double x, double y) : x(x), y(y) {}
    point(){}
    bool operator == (point& b) const {return x == b.x && y == b.y;}
    friend istream& operator >>(istream& in, point& p) {return in >> p.x >> p.y;}
};

double UK = 124.0;

const double dx[5] = {-0.5,  0.5, 0.5, -0.5, -0.5};
const double dy[5] = {-0.5, -0.5, 0.5,  0.5, -0.5};

double cross(point a, point b, point o)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

point lineIntersectSeg(point p, point q, point A, point B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> cutPolygon(point a, point b, vector<point>& Q)
{
    vector<point> P;
    for (int i = 0; i < Q.size(); ++i)
    {
        double left1 = cross(b, Q[i], a), left2 = 0;
        if (i != Q.size() - 1) 
            left2 = cross(b, Q[i + 1], a);
        if (left1 > -eps) P.push_back(Q[i]);
        if (left1 * left2 < -eps)
            P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front());
    return P;
}

double Area(vector<point>& P)
{
    if (P.size() < 3)
        return 0;
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        double x1 = P[i].x, x2 = P[i + 1].x;
        double y1 = P[i].y, y2 = P[i + 1].y;
        A += (x1 * y2 - x2 * y1);
    }
    return 0.5 * fabs(A);
}

int main()
{
    vector<point> P(5);
    while (cin >> P[0])
    {
        for (int i = 1; i < 4; ++i)
            cin >> P[i];
        P[4] = P[0];
        vector<vector<point> > cutP;
        for (int i = 0; i < 4; ++i)
        {
            point B(dx[i], dy[i]);
            point A(dx[i + 1], dy[i + 1]);
            cutP.emplace_back(cutPolygon(A, B, P));
        }
        
        double sum = 5 * 100.0 / UK;
        int dots[4] = {1, 3, 6, 4};
        for (int i = 0; i < 4; ++i)
            sum += dots[i] * Area(cutP[i]) * 5 / UK;
        cout << fixed << setprecision(10) << sum << '\n';
    }
}
