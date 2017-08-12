#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    cout << fixed << setprecision(3);
    while (cin >> n, t--)
    {
        if (n == 1)
            cout << 0.000 << '\n';
        else
            cout << sqrt(2) * (n - 2) * (n - 2) + 4 * n - 4 << '\n';
        if (t)
            cout << '\n';
    }
}
