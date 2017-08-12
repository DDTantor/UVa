#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define eps 1e-7

double p, q, r, s, t, u;

double f(double x)
{
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double Bisect()
{
    double lo = 0.0;
    double hi = 1.0;
    while (hi - lo > eps)
    {
        double m = (lo + hi) / 2;
        if (f(lo) * f(m) <= 0)
            hi = m;
        else
            lo = m;
    } 
    return lo;
}

int main()
{
    while (cin >> p >> q >> r >> s >> t >> u)
    {
        if (f(0) * f(1) > 0)
            cout << "No solution\n";
        else
            cout << fixed << setprecision(4) << Bisect() << '\n';
    }
}
