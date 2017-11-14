#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int dp[30][30], A[30], B[30];

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
    int n, a;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a, A[a - 1] = i;

    cin.ignore();
    string s;
    while (getline(cin, s))
    {
        istringstream iss(s);
        for (int i = 0; i < n; ++i)
            iss >> a, B[a - 1] = i;

        memset(dp, -1, sizeof dp);
        cout << lcs(n, n) << '\n';
    }
}
