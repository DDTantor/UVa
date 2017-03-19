#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int s = 1;
    double a, b, c, d1, d2;
    while (cin >> a >> b >> c, a != -1)
    {
        cout << "Set " << s++ << ":\n";
        if (b == 0)
            cout << "Poor King!\n";
        else
        {
            d1 = a * c / b;
            d2 = (a + d1) * (c + d1) / (b - d1);
            if (d1 < 0 || d2 < 0 || b == d1)
                cout << "Poor King!\n";
            else
                cout << fixed << setprecision(4) << d1 + d2 << '\n';
        }
    }
}
