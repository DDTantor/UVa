#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, u, v;
bool flag;
vvi G;
vi V, S;

void dfs(int id)
{
    V[id] = 1;
    for (int j : G[id])
    {
        flag |= (V[j] == 1);
        if (!V[j])
            dfs(j);
    }
    V[id] = 2;
    S.push_back(id);
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        G.clear();
        S.clear();
        G.assign(n, vi());
        V.assign(n, 0);
        for (int i = 0; i < m; ++i)
            cin >> u >> v, G[u - 1].push_back(v - 1);

        flag = false;
        for (int i = 0; i < n; ++i)
            if (!V[i])
                dfs(i);
        
        if (flag)
            cout << "IMPOSSIBLE\n";
        else
            for (int i = 0; i < n; ++i)
                cout << 1 + S[n - i - 1] << '\n';
    }
}
