#include <iostream>
#include <cmath> 
#include <numeric>
#include <iomanip>
#include <cstring>

using namespace std;

const int maxn = 104;

// f[n][k] = f[n - 1][k - 1] + f[n - 1][k] + f[n - 1][k + 1] 
int main()
{
    int n, k;
    double f[maxn][11];
    while (cin >> k >> n)
    {
        memset(f, 0, sizeof f);
        cout << fixed << setprecision(5);
        for (int i = 0; i < k + 1; ++i)
            f[1][i] = 1;
        
        for (int i = 2; i < n + 1; ++i)
        {
            for (int j = 0; j < k + 1; ++j)
            {
                if (j == 0)
                    f[i][j] = f[i - 1][j] + f[i - 1][j + 1];
                else if (j == k)
                    f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                else
                    f[i][j] = f[i - 1][j] + f[i - 1][j + 1] + f[i - 1][j - 1];
            }
        }

        double r = accumulate(f[n], f[n] + k + 1, 0.0) / pow((double)k + 1, n);
        cout << 100.0 * r << '\n';
    }
}
