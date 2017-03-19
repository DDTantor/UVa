#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double Area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s -c ));
}

double Sector(double r, double kut)
{
    return kut/2 * r * r;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double r1, r2, r3;
        cin >> r1 >> r2 >> r3;
        double a = r3 + r1, b = r1 + r2, c = r2 + r3;
        double alfa = acos((b * b + c * c - a * a) / (2 * b * c));
        double beta = acos((a * a + c * c - b * b) / (2 * a * c));
        double gama = acos((a * a + b * b - c * c) / (2 * a * b));
        double res = Area(a, b, c) - Sector(r2, alfa) - Sector(r3, beta) - Sector(r1, gama);
        cout << fixed << setprecision(6) << res << '\n';
    }
    
}
