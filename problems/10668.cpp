#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define eps 1e-6

double h, l, s, dt, c;

double Calc(double h)
{
    double r = l * l / (8.0 * h) + h / 2.0;
    return asin(l / (2 * r)) * (2 * r);
}

int main()
{
    while (cin >> l >> dt >> c, l >= 0)
    {
        s = (1 + c * dt) * l;
        double lo = 0, hi = l / 2.0, h;
        while (fabs(lo - hi) > eps)
        {
            h = (lo + hi) / 2.0;
            (Calc(h) > s ? hi : lo) = h;
        }

        cout << fixed << setprecision(3)  << lo << '\n';
    }
}
