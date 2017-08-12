#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

int main()
{
    ll t, cs = 0, n, m, k, P[100][100], A[100][100];
    cin >> t;
    while (cin >> n >> m >> k, t--)
    {
        cout << "Case #" << ++cs << ": ";

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                A[i][j] = 1;
                cin >> P[i][j];
                if (i > 0)
                    A[i][j] += A[i - 1][j], P[i][j] += P[i - 1][j];
                if (j > 0)
                    A[i][j] += A[i][j - 1], P[i][j] += P[i][j - 1];
                if (i > 0 && j > 0)
                    A[i][j] -= A[i - 1][j - 1], P[i][j] -= P[i - 1][j - 1];
            }
        }
        ll bestsz = 0, bestcost = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int x = i; x < n; ++x)
                {
                    for (int y = j; y < m; ++y)
                    {
                        int cost = P[x][y], sz = A[x][y];
                        if (i > 0)
                            sz -= A[i - 1][y], cost -= P[i - 1][y];
                        if (j > 0)
                            sz -= A[x][j - 1], cost -= P[x][j - 1];
                        if (i > 0 && j > 0)
                            sz += A[i - 1][j - 1], cost += P[i - 1][j - 1];
                        if ((sz > bestsz && cost <= k) || (sz == bestsz && bestcost > cost))
                            bestsz = sz, bestcost = cost;
                    }
                }
            }
        }
        cout << bestsz << ' ' << bestcost << '\n';
    }
}
