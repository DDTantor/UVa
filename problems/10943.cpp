#include <iostream>
#include <cstring>

using namespace std;

int n, K, dp[101][101], MOD = 1e6;

int ways(int x, int w)
{
    if (w == 1)
        return 1;

    if (dp[x][w])
        return dp[x][w];

    for (int i = 0; i <= x; ++i)
        dp[x][w] = (dp[x][w] + ways(x - i, w - 1)) % MOD;

    return dp[x][w];
}

int main()
{
    memset(dp, 0, sizeof(dp));
    while (cin >> n >> K, n || K)
        cout << ways(n, K) << '\n'; 
}
