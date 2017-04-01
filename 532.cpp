#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

string S[30][30];
int m, n, l, B[30][30][30];

typedef tuple<int, int, int, int> iiii;

const int dx[6] = { 0,  0,  0,  1,  0, -1};
const int dy[6] = { 0,  0, -1,  0,  1,  0};
const int dz[6] = {-1,  1,  0,  0,  0,  0};
int BFS(int x, int y, int z)
{
    queue<iiii> Q;
    int cnt;
    Q.emplace(0, x, y, z);
    B[z][y][x] = 0;
    while (!Q.empty())
    {
        tie(cnt, x, y, z) = Q.front(); Q.pop();
        for (int i = 0; i < 6; ++i)
        {
            int xx = x + dx[i], yy = y + dy[i], zz = z + dz[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && zz >= 0 && zz < l && S[zz][yy][xx] != '#')
            {
                if (S[zz][yy][xx] == 'E')
                    return cnt + 1;
                S[zz][yy][xx] = '#', Q.emplace(cnt + 1, xx, yy, zz);
            }
        }
    }
    return 0;
}

int main()
{
    int x, y, z;
    while (cin >> l >> m >> n, l || m || n)
    {
        memset(B, -1, sizeof(B));
        for (int i = 0; i < l; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin>> S[i][j];
                for (int k = 0; k < n; ++k)
                    if (S[i][j][k] == 'S')
                        z = i, y = j, x = k;
            }
        }
        int cnt = BFS(x, y, z);
        if (cnt)
            cout << "Escaped in " << cnt << " minute(s).\n";
        else
            cout << "Trapped!\n";
    }
}
