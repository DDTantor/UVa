#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int dx[4] = {1, 0, 1, 0};
int dy[4] = {0, 0, 1, 1};

int main()
{
    int n, m;
    double a, x, y;
    while (cin >> n >> a, n || a)
    {
        m = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y;
            bool flag = true;
            for (int j = 0; j < 4; ++j)
                flag &= (hypot(x - dx[j] * a, y - dy[j] * a) <= a);
            m += flag;
        }
        double res = (double)m / n * a * a;
        cout << fixed << setprecision(5) << res << '\n';
    }
}
