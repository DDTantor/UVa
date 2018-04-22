#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m, q, cs = 1, u, v, w, D[100][100];
    while (cin >> n >> m >> q, n + m + q)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = (i == j? 0 : 1e9);
        
        cout << "Case #" << cs++ << '\n';
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w, --u, --v;
            D[u][v] = D[v][u] = w;
        }
    
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    D[i][j] = min(D[i][j], max(D[i][k], D[k][j]));

        while (q--)
        {
            cin >> u >> v, --u, --v;
            if (D[u][v] == 1e9)
                cout << "no path\n";
            else
                cout << D[u][v] << '\n';
        }

        cin.ignore();
        if (cin.peek() != '0')
            cout << '\n';
    }
}
