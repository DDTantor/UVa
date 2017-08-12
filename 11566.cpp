#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

int n, x, t, a, k, W[201], V[201];

int val(int id, int c, int num, vvvi& dp)
{
    if (id == 2 * k || num == 2 * n || c <= 0)
        return 0;

    if (dp[id][c][num])
        return dp[id][c][num];

    if (W[id] > c)
        return dp[id][c][num] = val(id + 1, c, num, dp);

    return dp[id][c][num] = max(val(id + 1, c, num, dp), V[id] + val(id + 1, c - W[id], num + 1, dp));
}

int main()
{
    while (cin >> n >> x >> t >> k, n || x || t || k)
    {
        n++;
        memset(V, 0, sizeof(V));
        for (int i = 0; i < k; ++i)
        {
            cin >> W[i];
            W[i + k] = W[i];
            for (int j = 0; j < n; ++j)
                cin >> a, V[i] += a;
            
            V[i + k] = V[i];
        }
        x = floor(double(x * n) / 1.1 + 1e-6) - n * t;
        vvvi dp(2 * k, vvi(x + 1, vi(2 * n, 0)));
        cout << fixed << setprecision(2) << (double)val(0, x, 0, dp) / n << '\n';
    }
}
