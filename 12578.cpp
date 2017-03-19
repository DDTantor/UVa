#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    double L, R, W;
    cin >> t;
    while (cin >> L, t--)
    {
        R = L / 5.0;
        W = 6 * L / 10.0;
        double A1 = R * R * M_PI, A2 = L * W - A1;
        cout << fixed << setprecision(2) << A1 << ' ' << A2 << '\n';
    }
}
