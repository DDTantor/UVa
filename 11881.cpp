#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

typedef long double ld;

#define eps 1e-5

int n, CF[11];


double f(double x)
{
    double sum = 0.0;
    for (int i = 0; i <= n; ++i)
        sum += ((double)CF[i]) / pow(1.0 + x, i);
    return sum;
}

double Bisect()
{
    double hi = 1000000.0, lo = -0.9999;
    while (hi - lo > eps)
    {
        double x = (lo + hi) / 2.0;
        double fx = f(x), fh = f(hi);
        if ((fh < 0 && fx > 0) || (fh >= 0 && fx > fh)|| (fh <= 0 && fh > fx))
            lo = x;
        else 
            hi = x;
    }
    return hi;
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i <= n; ++i)
            cin >> CF[i];
        cout << fixed << setprecision(2) << Bisect() << '\n';
        
    }
}
