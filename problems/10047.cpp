#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, int, int> state;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, sx, sy, ex, ey, V[25][25][4][5], cs;
string G[25];

int Mod(int a, int mod)
{
    return a < 0 ? a + mod : a % mod;
}

bool Valid(int x, int y)
{
    return x >= 0 && y >= 0 && x < n && y < m && G[x][y] != '#';
}

int bfs()
{
    memset(V, 0, sizeof V);
    queue<state> Q;
    Q.emplace(0, sx, sy, 0, 0);
    V[sx][sy][0][0] = 1;
    while (!Q.empty())
    {
        int dist, x, y, ori, col;
        tie(dist, x, y, ori, col) = Q.front(); Q.pop();
        if (x == ex && y == ey && col == 0)
            return dist;

        for (int k = -1; k < 2; ++k)
        {
            int nori = Mod(ori + k, 4);
            int xx = x + (!k ? dx[ori] : 0), yy = y  + (!k ? dy[ori] : 0);
            int ncol = Mod(col + (k == 0), 5);
            if (Valid(xx, yy) && !V[xx][yy][nori][ncol])
                V[xx][yy][nori][ncol] = 1, Q.emplace(dist + 1, xx, yy, nori, ncol);
        }
    }

    return -1;
}

int main()
{
    while (cin >> n >> m, n + m)
    {
        cout << "Case #" << ++cs << '\n';
        for (int i = 0; i < n; ++i)
        {
            cin >> G[i];
            for (int j = 0; j < m; ++j)
            {
                if (G[i][j] == 'S')
                    sx = i, sy = j;

                if (G[i][j] == 'T')
                    ex = i, ey = j;
            }
        }

        int steps = bfs();
        if (steps != -1)
            cout << "minimum time = " << steps << " sec\n";
        else
            cout << "destination not reachable\n";

        cin.ignore();
        if (cin.peek() != '0')
            cout << '\n';
    }
}
