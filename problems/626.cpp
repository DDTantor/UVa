#include <iostream>
#include <cstring>

using namespace std;

int G[100][100], V[100][100][100], n, cnt;

bool good(int i, int j, int k)
{
    bool i1 = G[i][j] && G[j][k] && G[k][i] && !V[i][j][k] && !V[k][i][j] && !V[j][k][i];
    bool i2 = (i < j && j < k) || (i > j && j > k);
    return i1 && i2;
}

int main()
{
    while (cin >> n)
    {
        memset(G, 0, sizeof(G));
        memset(V, 0, sizeof(V));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> G[i][j];

        cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = 0; k < n; ++k)
                {
                    if (good(i, j, k))
                    {
                        cout << i + 1 << ' ' << j + 1 << ' ' << k + 1 << '\n';
                        V[i][j][k] = V[k][i][j] = V[j][k][i] = 1;
                        cnt++;
                    }
                }
            }
        }
        cout << "total:" << cnt << "\n\n";
    }
}
