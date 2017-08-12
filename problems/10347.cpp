#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    double t1, t2, t3;
    while (cin >> t1 >> t2 >> t3)
    {
        if (t1 + t2 <= t3 || t1 + t3 <= t2 || t2 + t3 <= t1)
            cout << "-1.000\n";
        else
            cout << fixed << setprecision(3) << 3 * Area(2 / 3.0 * t1, 2 / 3.0 * t2, 2 / 3.0 * t3) << '\n';
    }
}
