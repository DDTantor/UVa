#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple> 

using namespace std;

typedef tuple<int, int, int, int> robot;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int turn[2] = {1, 3};
const string O = "nesw";

bool visited[50][50][4];
int orientation, G[50][50], x, y, m, n, ex, ey;

bool valid(int u, int v)
{
    if (u <= 0 || v <= 0 || u >= m || v >= n) return false;
    if (G[u][v] || G[u - 1][v] || G[u][v - 1] || G[u - 1][v - 1]) return false;

    return true;
}

int bfs()
{
    if (!valid(x, y))
        return -1;
    
    queue<robot> Q;
    Q.emplace(x, y, 0, orientation);
    visited[x][y][orientation] = 1;
    while (!Q.empty())
    {
        int u, v, d, o;
        tie(u, v, d, o) = Q.front(); Q.pop();

        if (u == ex && v == ey)
            return d;
        
        for (int k = 1; k <= 3; ++k)
        {
            int uu = u + k * dx[o], vv = v + k * dy[o];
            if (!valid(uu, vv))
                break;
            
            if (visited[uu][vv][o])
                continue;
            
            visited[uu][vv][o] = true;
                Q.emplace(uu, vv, d + 1, o);
        }

        for (int l = 0; l < 2; ++l)
        {
            int t = (o + turn[l]) % 4;
            if (!visited[u][v][t])
                visited[u][v][t] = true, Q.emplace(u, v, d + 1, t);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> m >> n, m || n)
    {
        memset(visited, false, sizeof visited);
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> G[i][j];

        string s;
        cin >> x >> y >> ex >> ey >> s;
        orientation = O.find(s[0]);
        cout << bfs() << '\n';
    }
}
