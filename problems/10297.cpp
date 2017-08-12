#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double V, D, d;
    while (cin >> D >> V, V || D)
        cout << fixed << setprecision(3) << cbrt(D * D * D - 6 * V / M_PI) << '\n';
}
