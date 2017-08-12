#include <iostream>
#include <vector>
#include <stack>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

stack<int> S;

void dfs(bool V[100], const vvi& G, int u)
{
    V[u] = true;
    for (auto v : G[u])
        if (!V[v])
            dfs(V, G, v);
    S.push(u);
}

int main()
{
    int n, s,cs = 1;
    while (cin >> n, n)
    {
        cin >> s;
        s--;
        vvi G(n);
        int u, v;
        while (cin >> u >> v, u || v)
            G[u - 1].push_back(v - 1);
        bool flag = false, V[100] = {};
        dfs(V, G, s);
        int ind = 0, m = 0, D[100] = {};
        while (!S.empty())
        {
            int u = S.top(); S.pop();
            for (auto v : G[u])
            {
                if (D[u] + 1 > D[v])
                {
                    D[v] = D[u] + 1;
                    if (m == D[v])
                        ind = min(ind, v);
                    else if (m < D[v])
                        m = D[v], ind = v;
                }
            }
        }
        cout << "Case " << cs++ << ": The longest path from " << s + 1 << " has length " << m << ", finishing at " << ind + 1 << ".\n\n";
    }
}
