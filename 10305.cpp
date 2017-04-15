#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

stack<int> S;

void dfs(const vvi& G, bool V[100], int u)
{
    V[u] = true;
    for (auto v : G[u])
        if (!V[v])
            dfs(G, V, v);
    S.push(u);
}

int main()
{
    int m, n;
    while (cin >> m >> n, m || n)
    {
        vvi G(m);
        int u, v;
        for (int i = 0; i < n; ++i)
        {
            cin >> u >> v;
            u--, v--;
            G[u].push_back(v);
        }
        bool V[100] = {};
        for (int i = 0; i < m; ++i)
            if (!V[i])
                dfs(G, V, i);
        while (!S.empty())
        {
            cout << S.top() + 1 << ' ';
            S.pop();
        }
        cout << '\n';
    }
}
