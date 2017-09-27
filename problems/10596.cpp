#include <iostream>
#include <cstring>

using namespace std;

int n, r, u, v, A[200], G[200][200], V[200];

void dfs(int id)
{
    V[id] = true;
    for (int i = 0; i < n; ++i)
        if (!V[i] && G[id][i])
            dfs(i);
}

int main()
{

    while (cin >> n >> r)
    {
        memset(G, 0, sizeof(G));
        memset(V, true, sizeof(V));
        memset(A, 0, sizeof(A));
        for (int i = 0; i < r; ++i)
        {
            cin >> u >> v;
            G[u][v] = G[v][u] = 1;
            A[u]++, A[v]++;
            V[u] = V[v] = false;
        }
        bool flag = true;
        for (int i = 0; i < n; ++i)
            flag &= !(A[i] % 2);
        
        if (!flag)
            cout << "Not Possible\n";
        else
        {
            int cnt = 0;
            for (int i = 0; i < n; ++i)
                if (!V[i])
                    dfs(i), cnt++;
            if (cnt == 1)
                cout << "Possible\n";
            else
                cout << "Not Possible\n";
        }
    }
}
