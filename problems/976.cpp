#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int MAX = int(1e9);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int dp[maxn][maxn], r, c, b, s, A[maxn];
string S[maxn];

bool valid(int x, int y, char ch)
{
    return x >= 0 && y >= 0 && x < r && y < c && S[x][y] == '#' && S[x][y] != ch;
}

void dfs(int x, int y, char ch)
{
    for (int k = 0; k < 4; ++k)
        if (valid(x + dx[k], y + dy[k], ch))
            S[x + dx[k]][y + dy[k]] = ch, dfs(x + dx[k], y + dy[k], ch);
}

int val(int id, int num)
{
    if (id >= c && num)
        return MAX;

    if (!num)
        return 0;

    if (dp[id][num] != -1)
        return dp[id][num];

    return dp[id][num] = min(val(id + s + 1, num - 1) + A[id], val(id + 1, num));
}

int main()
{
    while (cin >> r >> c >> b >> s)
    {
        memset(dp, -1, sizeof dp);
        memset(A, 0, sizeof A);
        for (int i = 0; i < r; ++i)
            cin >> S[i];

        dfs(0, 0, '1');
        dfs(r - 1, 0, '2');
        for (int j = 0; j < c; ++j)
            for (int i = 0, fl = 0; i < r && !fl; ++i)
                if (S[i][j] == '2')
                    for (int k = i - 1; k >= 0 && S[k][j] != '1'; ++fl, ++A[j], --k);

        cout << val(0, b) << '\n';
    }
}
