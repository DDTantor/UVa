#include <iostream>
#include <climits>

using namespace std;

int t, sx, sy, n, X[11], Y[11], D[11][11], dp[11][1 << 11];

int tsp(int pos, int m)
{ 
    if (m == (1 << n) - 1)
        return D[pos][0];

    if (dp[pos][m] != 41)
        return dp[pos][m];

    for (int i = 0; i < n; ++i)
        if (i != pos && (m & (1 << i)) == 0)
            dp[pos][m] = min(dp[pos][m], D[pos][i] + tsp(i, m | (1 << i)));
    
    return dp[pos][m];
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> sx >> sy >> X[0] >> Y[0];
        cin >> n;
        n++;
        for (int i = 1; i < n; ++i)
            cin >> X[i] >> Y[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = abs(X[i] - X[j]) + abs(Y[i] - Y[j]);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < (1 << n); ++j)
                dp[i][j] = 41;

        cout << "The shortest path has length " << tsp(0, 1) << '\n';
    }
}
