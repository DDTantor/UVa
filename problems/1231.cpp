#include <iostream>
#include <cstring>

using namespace std;

int A[2000][2000], dp[2000][2000];

int main()
{
    int c, t, h, f, k, id;
    cin >> c;
    while (cin >> t >> h >> f, c--)
    {
        memset(A, 0, sizeof A);
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < t; ++i)
        {
            cin >> k;
            for (int j = 0; j < k; ++j)
                cin >> id, A[i][h - id]++;
        }
        
        for (int i = 0; i < t; ++i)
            dp[0][i] = A[i][0];
        
        for (int i = 1; i < h; ++i)
        {
            for (int j = 0; j < t; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (i >= f)
                    for (int l = 0; l < t; ++l)
                        if (l != j)
                            dp[i][j] = max(dp[i][j], dp[i - f][l]);
                
                dp[i][j] += A[j][i];
            }

        }

        int res = 0;
        for (int i = 0; i < t; ++i)
            res = max(res, dp[h - 1][i]);

        cout << res << '\n';
    }
}
