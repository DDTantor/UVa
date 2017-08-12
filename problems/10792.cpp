#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double r, d, h;
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        cin >> r >> d >> h;
        cout << "Case " << c++ << ": ";
        double s = 2 * sqrt(r * r - (r - d) * (r - d));
        double beta = asin((r - d) / r);
        double alfa = asin((r - h) / r);
        double x = h + s * sin(alfa - beta);
        cout << fixed << setprecision(4) << x << '\n';
    }
}
