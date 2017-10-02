#include <iostream>
#include <cstring>

using namespace std;

int m, n, best, u, v, w, G[25][25];

int dfs(int id, int len)
{
    best = max(best, len);
    for (int i = 0; i < n; ++i)
        if (G[id][i])
            G[id][i] = G[i][id] = 0,  dfs(i, len + 1), G[id][i] = G[i][id] = 1;
}

int main()
{
    while (cin >> n >> m, m || n)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; ++i)
            cin >> u >> v, G[u][v] = G[v][u] = 1;

        best = 0;
        for (int i = 0; i < n; ++i)
            dfs(i, 0);

        cout << best << '\n';
    }
}

