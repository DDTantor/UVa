#include <iostream>
#include <cstring>

using namespace std;

int dp[501][501];

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    
    if (dp[a][b] != -1)
        return dp[a][b];

    return gcd(b, a % b);
}

int main()
{
    int n;
    memset(dp, -1, sizeof dp);
    while (cin >> n, n)
    {
        int sum = 0;
        for (int i = 1; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                sum += gcd(i, j);
            
        cout << sum << '\n';
    }
}
