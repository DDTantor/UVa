#include <iostream>
#include <cstring>

using namespace std;

int n, m, A[1000], B[1000], dp[1000][1000], num[1000][1000];
string NA[1000], NB[1000];

bool cmp(int i, int j, int k, int l)
{
    return (dp[i][j] > dp[k][l] || (dp[i][j] == dp[k][l] && num[i][j] < num[k][l]));
}

int main()
{
    ios::sync_with_stdio(false);
    int t, string;
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> NA[i] >> NA[i] >> A[i];

        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> NB[i] >> NB[i] >> B[i];

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                dp[i][j] = num[i][j] = 0;
                
                if (NA[i] == NB[j])
                {
                    dp[i][j] = A[i] + B[j] + (i > 0 && j > 0? dp[i - 1][j - 1] : 0);
                    num[i][j] = 1 + (i > 0 && j > 0? num[i - 1][j - 1] : 0);
                }

                if (i > 0 && cmp(i - 1, j, i, j))
                    dp[i][j] = dp[i - 1][j], num[i][j] = num[i - 1][j];

                if (j > 0 && cmp(i, j - 1, i, j))
                    dp[i][j] = dp[i][j - 1], num[i][j] = num[i][j - 1];
            }
        }

        cout << dp[n - 1][m - 1] << ' ' << num[n - 1][m - 1] << '\n'; 
    }
}
