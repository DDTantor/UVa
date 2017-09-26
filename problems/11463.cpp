#include <iostream>

using namespace std;

int G[100][100], t, n, r, u, v, c = 0;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> r;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] = (i == j? 0 : 101);

        for (int i = 0; i < r; ++i)
        {
            cin >> u >> v;
            G[u][v] = G[v][u] = 1;
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        
        cin >> u >> v;
        int best = 0;
        for (int i = 0; i < n; ++i)
            if (G[u][i] != 101 && G[v][i] != 101)
                best = max(best, G[u][i] + G[v][i]);

        cout << "Case " << ++c << ": " << best << '\n';
    }
}
