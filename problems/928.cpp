#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef tuple<int, int, int, int> state;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int mv[3] = {1, 2, 3};

string G[300];
int n, m, t, sx, sy, ex, ey, V[300][300][3];

bool Valid(int x, int y, int k, int move)
{
    for (int i = 1; i <= move; ++i)
    {
        x += dx[k], y += dy[k];
        if (x < 0 || y < 0 || x >= n || y >= m || G[x][y] == '#')
            return false;
    }
    
    return true;
}

int bfs()
{
    memset(V, 0, sizeof V);
    queue<state> Q;
    Q.emplace(0, sx, sy, 0);
    V[sx][sy][0] = 1;
    while (!Q.empty())
    {
        int dist, x, y, move;
        tie(dist, x, y, move) = Q.front(); Q.pop();
        if (x == ex && y == ey)
            return dist;

        for (int k = 0; k < 4; ++k)
        {
            int xx = x + mv[move] * dx[k], yy = y + mv[move] * dy[k];
            int nmove = (move + 1) % 3;
            if (Valid(x, y, k, mv[move]) && !V[xx][yy][nmove])
                V[xx][yy][nmove] = 1, Q.emplace(dist + 1, xx, yy, nmove);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (cin >> n >> m, t--)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> G[i];
            for (int j = 0; j < m; ++j)
            {
                if (G[i][j] == 'S')
                    sx = i, sy = j;

                if (G[i][j] == 'E')
                    ex = i, ey = j;
            }
        }

        int steps = bfs();
        cout << (steps != -1 ? to_string(steps) : "NO") << '\n';
    }   
}
