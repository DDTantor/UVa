#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double l, w, h, theta;
    while (cin >> l >> w >> h >> theta)
    {
        double Vol, h1 = l * tan(theta * M_PI / 180);
        if (h1 > h)
            Vol = (h * l * h / h1) / 2 * w;
        else
            Vol = (l * h - l * h1 / 2) * w;
        cout << fixed << setprecision(3) << max(Vol, 0.0) << " mL\n";
    }
}
