#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;

const int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

string S[20];
int n, m, sx, sy, cx[16], cy[16], cnt, D[16][20][20], dp[16][1 << 16];

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void bfs(int id)
{
    queue<iii> Q;
    D[id][cx[id]][cy[id]] = 0;
    Q.emplace(0, cx[id], cy[id]);
    while (!Q.empty())
    {
        int d, x, y;
        tie(d, x, y) = Q.front(); Q.pop();
        //cout << x << ' ' << y << endl;
        for (int k = 0; k < 8; ++k)
        {
            int xx = x + dx[k], yy = y + dy[k];
            if (valid(xx, yy) && D[id][xx][yy] == -1)
                D[id][xx][yy] = d + 1, Q.emplace(d + 1, xx, yy);
        }
    }
}

int tsp(int id, int mask)
{
    if (mask == (1 << cnt) - 1)
        return D[id][cx[0]][cy[0]];

    if (dp[id][mask] != -1)
        return dp[id][mask];

    int res = 1e9;
    for (int i = 0; i < cnt; ++i)
        if (i != id && !(mask & (1 << i)))
            res = min(res, D[id][cx[i]][cy[i]] + tsp(i, mask | (1 << i)));
        
    return dp[id][mask] = res;
}

int main()
{
    while (cin >> n >> m)
    {
        memset(D, -1, sizeof(D));
        memset(dp, -1, sizeof(dp));
        cnt = 1;
        for (int i = 0; i < n; ++i)
        {
            cin >> S[i];
            for (int j = 0; j < m; ++j)
            {
                if (S[i][j] == '#')
                    cx[cnt] = i, cy[cnt++] = j;
                else if (S[i][j] == 'L')
                    cx[0] = i, cy[0] = j;
            }
        }

        for (int i = 0; i < cnt; ++i)
            bfs(i);

        cout << tsp(0, 1) << '\n';
    }
}
