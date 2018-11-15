#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double r = 5000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cout << fixed << setprecision(4);
    while (cin >> n >> m)
    {
        double res = 0;
        for (int i = 1; i < n; ++i)
        {
            double pos = (n + m) * i * 1.0 / n;
            res += abs(pos - floor(pos + 0.5)) / (n + m);
        }

        cout << 2 * r * res << '\n';
    }
}
