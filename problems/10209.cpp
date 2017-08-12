#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a;
    while (cin >> a)
    {
        double P1 = 8 * (a * a / 2 - a * a / 24 * (3 * sqrt(3) + 2 * M_PI));
        double P2 = a * a * (M_PI / 2 - 1);
        double P3 = 2 * P2 + P1 - a * a;
        P2 = a * a - P1 - P3;
        cout << fixed << setprecision(3) << P3 << ' ' << P2 << ' ' << P1 << endl;
    }
}
    
