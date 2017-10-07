#include <iostream>
#include <cstring>

using namespace std;

#define inf 1e9

int main()
{
    long long G[100][100], T[100][100];
    int x, y, u, v, w, tm, t, q;
    cin >> t;
    while (cin >> x >> y, t--)
    {
        for (int i = 0; i < x; ++i)
            for (int j = 0; j < x; ++j)
                T[i][j] = G[i][j] = (i == j? 0 : inf);
        
        for (int i = 0; i < y; ++i)
        {
            cin >> u >> v >> tm >> w, u--, v--;
            if (tm < T[u][v] || (tm == T[u][v] && G[u][v] > w))
                G[u][v] = G[v][u] = w, T[u][v] = T[v][u] = tm;
        }

        for (int k = 0; k < x; ++k)
        {
            for (int i = 0; i < x; ++i)
            {
                for (int j = 0; j < x; ++j)
                {
                    if (T[i][j] > T[i][k] + T[k][j])
                        G[i][j] = G[i][k] + G[k][j], T[i][j] = T[i][k] + T[k][j];
                    else if (T[i][j] == T[i][k] + T[k][j] && G[i][j] > G[i][k] + G[k][j])
                        G[i][j] = G[i][k] + G[k][j];
                }
            }
        }
        
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            cin >> u >> v, u--, v--;
            if (G[u][v] == inf)
                cout << "No Path.\n";
            else
                cout << "Distance and time to reach destination is " << G[u][v] << " & " << T[u][v] << ".\n";
        }
        if (t)
            cout << '\n';
    }
}
