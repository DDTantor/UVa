#include <iostream>
#include <sstream>
#include <cstring>
#include <iomanip>

using namespace std;

int G[100][100];
bool U[100];

int main()
{
    int u, v, c = 0;
    while (cin >> u >> v, u || v)
    {
        cout << "Case " << ++c << ": average length between pages = "; 
        memset(G, 0, sizeof(G));
        memset(U, false, sizeof(U));
        int n = 0, num = 0;
        for (int i = 0; i < 100; ++i)
            for (int j = 0; j < 100; ++j)
                G[i][j] = (i == j? 0 : 1000);
        do
        {
            n = max(n, max(u, v));
            u--, v--;
            if (!U[u])
                num++, U[u] = true;
            if (!U[v])
                num++, U[v] = true;
            G[u][v] = 1;
        } while(cin >> u >> v, u || v);
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        
        double sum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                sum += G[i][j] * (G[i][j] != 1000);

        
        cout << fixed << setprecision(3) << sum / (num * (num - 1))  << " clicks\n";
    }
}
