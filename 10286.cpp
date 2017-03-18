#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double a;
    while (cin >> a)
        cout << fixed << setprecision(10) << a * sin(108 * M_PI / 180) / sin(63 * M_PI / 180) << '\n';
}
