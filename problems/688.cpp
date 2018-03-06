#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

double x[100], y[100], r[100], dx[200], dy[200];

double inside(int k, int l, int n)
{
    for (int i = 0; i < n; ++i)
        if (x[i] - r[i] <= dx[k - 1] && dx[k] <= x[i] + r[i] &&
            y[i] - r[i] <= dy[l - 1] && dy[l] <= y[i] + r[i])
            return (dx[k] - dx[k - 1]) * (dy[l] - dy[l - 1]); 

    return 0;
}

int main()
{
    int n, c = 1;

    cout << fixed << setprecision(2);
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> x[i] >> y[i] >> r[i];
            dx[i] = x[i] - r[i], dx[i + n] = x[i] + r[i];
            dy[i] = y[i] - r[i], dy[i + n] = y[i] + r[i];
        }
        
        sort(dx, dx + 2 * n);
        sort(dy, dy + 2 * n);
        double res = 0;
        for (int i = 1; i < 2 * n; ++i)
            for (int j = 1; j < 2 * n; ++j)
                res += inside(i, j, n);

        cout << c++ << ' ' << res << '\n';
    }
}
