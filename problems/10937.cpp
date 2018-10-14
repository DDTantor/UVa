#include <queue>
#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;

int maxd = 50 * 50;

const int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int w, h, root, D[50][50], V[50][50], cnt, ts;
vii A;
vvi dist, dp;
string S[50];

int tsp(int pos, int m)
{
    if (m == (1 << cnt) - 1)
        return dist[pos][root];

    if (dp[pos][m] != 1e9)
        return dp[pos][m];

    for (int i = 0; i < cnt; ++i)
        if (i != pos && (m & (1 << i)) == 0)
            dp[pos][m] = min(dp[pos][m], dist[pos][i] + tsp(i, m | (1 << i)));

    return dp[pos][m];
}

bool good(int x, int y, bool fl = false)
{
    return x >= 0 && x < h && y >= 0 && y < w && !V[x][y] &&
           (S[x][y] == '.' || S[x][y] == '@' || S[x][y] == '!' || fl);
}

int main()
{
    while (cin >> h >> w, w || h)
    {
        ++ts;
        
        cnt = 0;
        A.clear();
        for (int i = 0; i < h; ++i)
        {
            cin >> S[i];
            for (int j = 0; j < w; ++j)
            {
                if (S[i][j] == '@')
                    root = cnt;

                if (S[i][j] == '!' || S[i][j] == '@')
                A.emplace_back(i, j), D[i][j] = cnt++;
            }
        }

        memset(V, 0, sizeof(V));
        
        for (int i = 0; i < h; ++i)
        {
            for (int j = 0; j < w; ++j)
            {
                if (S[i][j] == '*' && !V[i][j])
                {
                    for (int k = 0; k < 8; ++k)
                    {
                        int xx = i + dx[k], yy = j + dy[k];
                        if (good(xx, yy))
                            V[xx][yy] = true, S[xx][yy] = '*';
                    }
                }
            }
        }

        dist.assign(cnt, vi(cnt, 1e9));
        dp.assign(cnt, vi(1 << cnt, 1e9));
        for (int i = 0; i < cnt; ++i)
            for (int j = 0; j < (1 << cnt); ++j)
                dp[i][j] = 1e9;
        
        for (int i = 0; i < cnt; ++i)
        {
            memset(V, 0, sizeof(V));
            queue<iii> Q;
            Q.emplace(A[i].first, A[i].second, 0);
            V[A[i].first][A[i].second] = true;
            while (!Q.empty())
            {
                int x, y, tm;
                tie(x, y, tm) = Q.front(); Q.pop();
                if (S[x][y] == '!' || S[x][y] == '@')
                    dist[i][D[x][y]] = tm;
                
                for (int k = 0; k < 8; k += 2)
                {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (good(xx, yy))
                        V[xx][yy] = true, Q.emplace(xx, yy, tm + 1);
                }

            }
        }

        int res = tsp(root, 0);
        cout << (cnt == 1? 0 : res != 1e9? res : -1) << '\n';
    }
}
