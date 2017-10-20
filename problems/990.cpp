#include <iostream>
#include <cstring>

using namespace std;

int w, dp[35][1005], t, n, D[35], G[35];
bool taken[35][1005], A[35];

int val(int id, int r)
{
    if (id < 0 || !r)
        return 0;

    if (dp[id][r] != -1)
        return dp[id][r];

    int a  = (r >= D[id]? val(id - 1, r - D[id]) + G[id] : 0);
    int b = val(id - 1, r);
    taken[id][r] = (a > b);
    return dp[id][r] = max(a, b);
}

int main()
{
    int cs = 0;
    while (cin >> t >> w >> n)
    {
        if (cs)
            cout << '\n';
        cs = 1;
        memset(dp, -1, sizeof(dp));
        memset(taken, 0, sizeof(taken));
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; ++i)
            cin >> D[i] >> G[i], D[i] *= (3 * w);

        cout << val(n - 1, t)  << '\n';
    
        int cnt = 0;
        for (int i = n - 1; i >= 0; --i)
            if (taken[i][t])
                A[i] = true, ++cnt, t = t - D[i];

        cout << cnt << '\n';
        for (int i = 0; i < n; ++i)
            if (A[i])
                cout << D[i] / (3 * w) << ' ' << G[i] << '\n';
    }
}
