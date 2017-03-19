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
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        double A = Area(a ,b , c);
        double r1 = 2 * A / (a + b + c);
        double R = r1 * r1 * M_PI;
        double V = A - R;
        double r2 = a * b * c / (4 * A);
        double S = r2 * r2 * M_PI  - R - V;
        cout << fixed << setprecision(4) << S << ' ' << V << ' ' << R << '\n';
    }
}
