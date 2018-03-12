#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (point& b) {return x < b.x || (x == b.x && y < b.y);}
    friend istream& operator >>(istream& in, point& p) {return in >> p.x >> p.y;}
};

double cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double angle(point a, point o, point b)
{
    point a_p = point(a.x - o.x, a.y - o.y), b_p = point(b.x - o.x, b.y - o.y);
    return acos(dot(a_p, b_p) / sqrt(dot(a_p, a_p) * dot(b_p, b_p)));
}

bool InPolygon(point& p, const vector<point>& P)
{
    double sum = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        if (cross(P[i], p, P[i + 1]) > 0)
            sum += angle(P[i], p, P[i + 1]);
        else
            sum -= angle(P[i], p, P[i + 1]);
    }
    
    return abs(abs(sum) - 2 * M_PI) < eps;
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
        if (InPolygon(pt, P))
            cout << "T\n";
        else
            cout << "F\n";
    }
}
