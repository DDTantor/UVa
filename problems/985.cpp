#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string S = "NESW", s;
int m, n, G[500][500][4];
bool V[500][500][4];

bool valid(int x, int y, int t)
{
    return (x >= 0 && x < n && y >= 0 && y < m && !V[x][y][t]);
}

int Solve()
{
    queue<iii> Q;
    int x, y, t;
    Q.emplace(0, 0, 0);
    V[0][0][0] = true;
    while (!Q.empty())
    {
        tie(x, y, t) = Q.front(); Q.pop();
        if (x == n - 1 && y == m - 1)
            return t;

        for (int k = 0; k < 4; ++k)
        {
            if (G[x][y][k])
            {
                int xx = x + dx[(k + t) % 4];
                int yy = y + dy[(k + t) % 4];
                if (valid(xx, yy, (t + 1) % 4))
                    Q.emplace(xx, yy, t + 1), V[xx][yy][(t + 1) % 4] = true;
            }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m)
    {
        memset(V, false, sizeof V);
        memset(G, false, sizeof G);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m && i + j != n + m - 2; ++j)
            {
                cin >> s;
                for (char c : s)
                    G[i][j][S.find(c)] = true;
            }
        }

        int res = Solve();
        if (res == -1)
            cout << "no path to exit\n";
        else
        cout << res << '\n';
    }
}
