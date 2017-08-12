#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    point operator -(point& b) {return point(x - b.x, y - b.y);}
    bool operator ==(point& b) const {return x == b.x && y == b.y;}
    friend istream& operator >>(istream& in, point& p) {return in >> p.x >> p.y;}
};

int c = 1;
point fn;

bool ccw(point& p, point& q, point& r)
{
    return (p.x - q.x) * (p.y - r.y) - (p.y - q.y) * (p.x - r.x) > 0;
}

double norm(point a)
{
    return hypot(a.x, a.y);
}

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

double angle(point& a, point& o, point& b)
{
    return acos(dot(a - o, b - o) / (norm(a - o) * norm(b - o)));
}

point lineIntersectSeg(point& p, point& q, point& A, point& B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

bool inPolygon(point pt, vector<point>& P)
{
    if(P.size() < 3)
        return false;
    double sum = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        if (ccw(pt, P[i], P[i + 1]))
            sum += angle(P[i], pt, P[i + 1]);
        else
            sum -= angle(P[i], pt, P[i + 1]);
    }
    return fabs(fabs(sum) - 2 * M_PI) < eps;
}

vector<point> cutPolygon(point& a, point& b, vector<point>& Q)
{
    vector<point> P;
    for (int i = 0; i < Q.size(); ++i)
    {
        double left1 = cross(b - a, Q[i] - a), left2 = 0;
        if (i != Q.size() - 1)
            left2 = cross(b - a, Q[i + 1] - a);
        if (left1 > -eps)
            P.push_back(Q[i]);
        if (left1 * left2 < -eps)
        {
            point pt = lineIntersectSeg(Q[i], Q[i + 1], a, b);
            P.push_back(pt);
        }
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
    int N;
    double W, H;
    while (cin >> N >> W >> H >> fn)
    {
        vector<point> P;
        P.emplace_back(0, 0);
        P.emplace_back(W, 0);
        P.emplace_back(W, H);
        P.emplace_back(0, H);
        P.emplace_back(0, 0);
        for (int i = 0; i < N; ++i)
        {
            point A, B;
            cin >> A >> B;
            if (ccw(A, B, fn))
                P = cutPolygon(A, B, P);
            else
                P = cutPolygon(B, A, P);
        }
        cout << fixed << "Case #" << c++ << ": " << setprecision(3) << Area(P) << endl;
    }
    
}
