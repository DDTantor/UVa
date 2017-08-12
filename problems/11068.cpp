#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int a1, b1, c1, a2, b2, c2;
    while (cin >> a1 >> b1 >> c1, a1 != 0 || b1 != 0 || c1 != 0)
    {
        cin >> a2 >> b2 >> c2;
        //Cramer
        int D1, D2, D = a1 * b2 - a2 * b1;
        if (D == 0)
            cout << "No fixed point exists.\n";
        else
        {
            D1 = c1 * b2- b1 * c2;
            D2 = a1 * c2 - c1 * a2;
            double x = (double)D1 / D;
            double y = (double)D2 / D;
            cout << fixed << setprecision(2) << "The fixed point is at " << x << ' ' << y << ".\n";
        }
    }
}
