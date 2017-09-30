#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;

const int dx[4] = {-1, 0, 1, 0};
const int dy[8] = {0, -1, 0, 1};

int R, C, r, c, n, b, G[1000][1000], u, sx, sy, ex, ey, d;

int main()
{
    while (cin >> R >> C >> n, R || C)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < n; ++i)
        {
            cin >> r >> b;
            for (int j = 0; j < b; ++j)
                cin >> c, G[r][c] = 1;
        }

        cin >> sy >> sx >> ey >> ex;
        queue<iii> Q;
        G[sy][sx] = G[ey][ex] = 8;
        Q.emplace(sx, sy, 0);
        while (!Q.empty())
        {
            tie(sx, sy, d) = Q.front(); Q.pop();
            if (sx == ex && sy == ey)
            {
                cout << d << '\n';
                break;
            }
            if (G[sy][sx] != -1)
            {
                G[sy][sx] = -1;
                for (int i = 0; i < 4; ++i)
                {
                    int tx = sx + dx[i], ty = sy + dy[i];
                    if (tx >= 0 && tx < C && ty >= 0 && ty < R && G[ty][tx] != 1)
                        Q.emplace(tx, ty, d + 1);
                        
                }
            }
        }
    }
}
