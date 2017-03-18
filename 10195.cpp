#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double rInCircle(double ab, double bc, double ca)
{
    return 2.0 * Area(ab, bc, ca) / (ab + bc + ca);
}

int main()
{
    double r, a, b, c;
    while (cin >> a >> b >> c)
    {
        r = ((!a || !b || !c)? 0 : rInCircle(a, b, c));
        cout << "The radius of the round table is: " << fixed << setprecision(3) << r << '\n'; 
    }
}
