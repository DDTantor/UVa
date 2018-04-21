#include <iostream>
#include <cstring>
#include <set> 

using namespace std;

typedef pair<int, int> ii;

int R, C, A[100][100], V[100][100], odd, even;
set<ii> moves;

void dfs(int x, int y)
{
    V[x][y] = 1;
    int cnt = 0;
    for (ii p : moves)
    {
        int xx = x + p.first, yy = y + p.second;
        if (xx >= 0 && xx < R && yy >= 0 && yy < C && !A[xx][yy])
        {
            ++cnt;
            if (!V[xx][yy]) dfs(xx, yy);
        }
    }

    (cnt % 2? odd : even)++;
}

int main()
{
    int c = 1, u, v, t, W, M, N;
    cin >> t;
    while (cin >> R >> C >> M >> N >> W, t--)
    {
        moves.clear();
        cout << "Case " << c++ << ": ";
        memset(A, 0, sizeof A);
        memset(V, 0, sizeof V);
        for (int i = 0; i < W; ++i)
        {
            cin >> u >> v;
            A[u][v] = 1;
        }

        for (int k = 0, i = 0, j = 0; k < 2; ++k)
        {
            for (int x = -1; x < 2; ++x)
                for (int y = -1; y < 2; ++y)
                    if (x && y)
                        moves.emplace(x * M, y * N);

            swap(M, N);
        }

        odd = even = 0;
        dfs(0, 0);
        
        cout << even << ' ' << odd << '\n';
    }
}
