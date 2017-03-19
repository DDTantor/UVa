#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n, c = 1;
    double A;
    while (cin >> n >> A, n >= 3)
    {
        cout << "Case " << c++ << ": ";
        double r, R, alfa = 2 *M_PI / n;
        R = sqrt(2 * A / (n * sin(alfa)));
        r = R * cos(alfa / 2);
        double P1 = R * R * M_PI - A;
        double P2 = A - r * r * M_PI;
        cout << fixed << setprecision(5) << P1 << ' ' << P2 << '\n';
    }
    
}
