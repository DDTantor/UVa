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
    int n, R;
    while (cin >> R >> n)
    {
        double r, I, E, angle = 180.0 / n;
        if (n == 1)
            r = R, I = E = 0;
        else
        {
            r = R * sin(angle * M_PI / 180) / (1 + sin(angle * M_PI / 180));
            I = n * (Area(2 * r, (R - r), (R - r)) - 2 * (r * r * M_PI / 360 * (90 - angle)));
            E = R * R * M_PI - (r * r * M_PI * n + I);
        }
        cout << fixed << setprecision(10) << r << ' ' << I << ' ' << E << '\n'; 
    }
    
}
