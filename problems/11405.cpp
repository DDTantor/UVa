#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>
#include <numeric>

using namespace std;

typedef tuple<int, int> piece;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
const int dy[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
    
string G[8];
int t, n, D[9][9], M[8][8], kx, ky, px[8], py[8], cnt;

int valid(int x, int y, vvi& V)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8 && G[x][y] != 'p' && G[x][y] != 'K';
}

void bfs(int id)
{
    vvi V(8, vi(8, -1));
    queue<piece> Q;
    if (id < cnt)
        Q.emplace(px[id], py[id]), V[px[id]][py[id]] = 0;
    else
        Q.emplace(kx, ky), V[kx][ky] = 0;
    
    while (!Q.empty())
    {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        for (int k = 0; k < 8; ++k)
        {
            int xx = x + dx[k], yy = y + dy[k];
            if (valid(xx, yy, V) && V[xx][yy] == -1)
            {
                Q.emplace(xx, yy), V[xx][yy] = V[x][y] + 1;
                if (G[xx][yy] == 'P' || G[xx][yy] == 'k')
                    D[id][M[xx][yy]] = V[x][y] + 1;
            }
        }
    }
}

int main()
{
    cin >> t;
    while (cin >> n, t--)
    {
        memset(M, 0, sizeof(M));
        memset(D, 0, sizeof(D));
        cnt = 0;
        for (int i = 0; i < 8; ++i)
        {
            cin >> G[i];
            for (int j = 0; j < 8; ++j)
            {
                if (G[i][j] == 'P')
                    M[i][j] = cnt, px[cnt] = i, py[cnt++] = j;

                if (G[i][j] == 'k')
                    kx = i, ky = j;
            }
        }

        M[kx][ky] = cnt;
        bfs(cnt);
        for (int i = 0; i < cnt; ++i)
          bfs(i);

        bool fl = 1;
        for (int i = 0; i < cnt; ++i)
            fl = fl && D[cnt][i];

        if (cnt)
        {
            int best = 1e9;
            vi p(cnt);
            iota(p.begin(), p.end(), 0);
            do
            {
                int sum = D[cnt][p[0]];
                for (int i = 1; i < cnt; ++i)
                    sum += D[p[i - 1]][p[i]];
                
            best = min(sum, best);
            } while (next_permutation(p.begin(), p.end()));
            
            cout << (best <= n && best && fl? "Yes\n" : "No\n");
        }
        else
            cout << "Yes\n";    }
}
