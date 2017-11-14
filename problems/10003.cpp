#include <iostream>
#include <cstring>

using namespace std;

int L, n, A[51], dp[51][51];

int cut(int l, int r)
{
    if (l + 1 == r)
        return 0;

    if (dp[l][r] != -1)
        return dp[l][r];

    int res = int(1e9);
    for (int i = l + 1;  i < r; ++i)
        res = min(res, cut(l, i) + cut(i, r) + (A[r] - A[l]));

    return dp[l][r] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> L >> n, L)
    {
        A[0] = 0;
        for (int i = 1; i <= n; ++i)
            cin >> A[i];

        A[n + 1] = L;
        memset(dp, -1, sizeof dp);
        cout << "The minimum cutting is " << cut(0, n + 1) << ".\n";
    }
}
