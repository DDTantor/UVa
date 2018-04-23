#include <iostream>

using namespace std;

const int mod = 1000007;
const int dx[2] = {1, 1};
const int dy[2] = {-1, 1};

string G[100];
int t, n, A[100][100], cs;

bool valid(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < n && G[x][y] != 'B';
}

int main()
{
    ios::sync_with_stdio(false);
    string G[100];
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> G[i];
            for (int j = 0; j < n; ++j)
                A[i][j] = (G[i][j] == 'W');
        }

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < 2; ++k)
                {
                    if (G[i][j] == 'B') continue;
                    int x = i + dx[k], y = j + dy[k];
                    if (!valid(x, y)) continue;
                    if (G[x][y] == 'B')
                    {
                        x += dx[k], y += dy[k];
                        if (!valid(x, y)) continue;
                    }

                    A[i][j] = (A[i][j] + A[x][y]) % mod;
                }
            }
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i)
            res = (res + (G[0][i] != 'B') * A[0][i]) % mod;

        cout << "Case " << ++cs << ": " << res << '\n';
    }
}
