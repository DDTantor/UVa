#include <iostream>
#include <cstring>

using namespace std;

string A, B;
int dp[1001][1001];

int lcs(int m, int n)
{
    if (m == 0 || n == 0)
        return 0;

    if (dp[m][n] != -1)
        return dp[m][n];
    
    if (A[m - 1] == B[n - 1])
        return dp[m][n] = 1 + lcs(m - 1, n - 1);
    else
        return dp[m][n] = max(lcs(m, n - 1), lcs(m - 1, n));
}

int main()
{
    ios::sync_with_stdio(false);
    while (getline(cin, A), getline(cin, B))
    {
        memset(dp, -1, sizeof dp);
        cout << lcs(A.size(), B.size()) << '\n';
    }
}
