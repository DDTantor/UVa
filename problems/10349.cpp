#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn = 40;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

string G[maxn];
int M[maxn][maxn], V[maxn][maxn], t, n, m;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m && G[x][y] == '*';
}

int Aug(int x, int y)
{
    if (V[x][y])
        return 0;

    V[x][y] = true;
    for (int k = 0; k < 4; ++k)
    {
        int xx = x + dx[k], yy = y + dy[k];
        if (!valid(xx, yy))
            continue;

        int ix = M[xx][yy] / m, iy = M[xx][yy] % m;
        if (M[xx][yy] == -1 || Aug(ix, iy))
        {
            M[xx][yy] = x * m + y;
            return 1;
        }
    }

    return 0;
}

int main()
{
    cin >> t;
    while (cin >> n >> m, t--)
    {
        int MCBM = 0, cnt = 0;
        memset(M, -1, sizeof M);
        for (int i = 0; i < n; ++i)
            cin >> G[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (G[i][j] == '*')
                    ++cnt, memset(V, 0, sizeof V), MCBM += Aug(i, j);

        cout << cnt - MCBM / 2 << '\n';
    }
}
