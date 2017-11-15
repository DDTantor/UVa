#include <iostream>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int n, cs = 0, x[16], y[16];
double G[16][16], dp[1 << 16];

double solve(int used)
{
    if (used == (1 << n) - 1)
        return dp[used] = 0;
    
    if (dp[used] != -1.0)
        return dp[used];
    
    double res = 1e9;
    int id1, id2;
    for (id1 = 0; id1 < n; ++id1)
        if (!(used & (1 << id1)))
            break;
    
    for (id2 = id1 + 1; id2 < n; ++id2)
        if (!(used & (1 << id2)))
            res = min(res, G[id1][id2] + solve(used | (1 << id1) | (1 << id2)));

    return dp[used] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    string s;
    while (cin >> n, n)
    {
        n *= 2;
        for (int i = 0; i < n; ++i)
            cin >> s >> x[i] >> y[i];

        for (int i = 0; i < (1 << 16); ++i)
           dp[i] = -1.0;
        
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                G[i][j] = hypot(x[i] - x[j], y[i] - y[j]);

        cout << "Case " << ++cs << ": " << fixed << setprecision(2) << solve(0) << '\n';
    }
}
