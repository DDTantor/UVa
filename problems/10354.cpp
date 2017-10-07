#include <iostream>
#include <cstring>

using namespace std;

#define inf 1e9

int p, r, bh, of, yh, m, G1[100][100], G[100][100], u, v, w, C[100];

void FW(int A[100][100])
{
    for (int k = 0; k < p; ++k)
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                if (!C[j] && !C[i] && !C[k])
                    A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
}

int main()
{
    while (cin >> p >> r >> bh >> of >> yh >> m)
    {
        --bh, --of, --yh, --m;
        for (int i = 0; i < p; ++i)
            for (int j = 0; j < p; ++j)
                G[i][j] = G1[i][j] = (i == j? 0 : inf);

        for (int i = 0; i < r; ++i)
        {
            cin >> u >> v >> w;
            u--, v--;
            G[v][u] = G[u][v] = G1[v][u] = G1[u][v] = w;
        }

        memset(C, 0, sizeof(C));
        FW(G);
        for (int i = 0; i < p; ++i)
            C[i] = (G[bh][i] + G[i][of] == G[bh][of]);
               

        FW(G1);
        if (G1[yh][m] == inf || C[yh] || C[m])
            cout << "MISSION IMPOSSIBLE.\n";
        else
            cout << G1[yh][m] << '\n';
    }
}
