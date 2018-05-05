#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define eps 1e-11

double f(double a, double b)
{
    double r = sqrt(a * a + b * b) * 0.5;
    double alfa = M_PI - 2 * atan(a / b);
    return 2 * a + 2 * r  * alfa;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int a, b, cs = 1;
    char c;
    while (cin >> a >> c >> b)
    {
        double lo = 0, hi = 1e9;
        while (abs(lo - hi) >= eps)
        {
            double mid = 0.5 * (lo + hi);
            double x = mid / a * b;
            (f(mid, x) > 400 ? hi : lo) = mid;
        }

        cout << "Case " << cs++ << ": " << lo << ' ' << (lo / a) * b << '\n';
    }
}
