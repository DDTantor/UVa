#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, b, n, s, m;
    while (cin >> a >> b >> s >> m >> n, a)
        cout << fixed << setprecision(2) << 180 / M_PI * atan2(b * n, a * m)
             << ' ' << hypot(a * m, b * n) / s << '\n';
}
