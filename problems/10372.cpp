#include <iomanip>
#include <iostream>
#include <tuple> 
#include <cmath>
#include <algorithm>

using namespace std;

const int maxn = 100;

#define eps 1e-6
#define g 9.8

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    bool operator <(point& p) {return tie(x, y) < tie(p.x, p.y);}
}P[2 * maxn];

double f(point p, double v, double A)
{
    return p.x * tan(A) - 0.5 * g * p.x * p.x / (v * v * cos(A) * cos(A)) - p.y;
}

bool Intersects(double v, double A, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        double left1 = f(P[i], v, A), left2 = f(P[i + 1], v, A);
        if (left1 * left2 < -eps)
            return true;
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int n;
    while (cin >> n)
    {
        double d, D = 0, h;
        for (int i = 0; i < n; ++i)
        {
            cin >> h >> d;
            P[i] = point(D, h), P[n + i] = point(D + d, h);
            D += d;
        }

        sort(P, P + 2 * n);
        double lo = 0, hi = M_PI * 0.5;
        while (abs(lo - hi) > eps)
        {
            double A = 0.5 * (hi + lo);
            double v = sqrt(D * g / sin(2 * A));
            (Intersects(v, A, 2 * n)? lo : hi) = A;
        }

        cout <<  lo * 180 / M_PI << ' ' << sqrt(D * g / sin(2 * lo)) << '\n';
    }
}
