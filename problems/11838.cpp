#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi discovery, num, low, S;
int n, m, SCC, tick;

void tarjan(int u)
{
    low[u] = num[u] = tick++;
    S.push_back(u);
    discovery[u] = 1;
    for (int v : G[u])
    {
        if (num[v] == -1)
            tarjan(v);
        if (discovery[v])
            low[u] = min(low[u], low[v]);
    }
    if (low[u] == num[u])
    {
        SCC++;
        while (true)
        {
            int v = S.back(); S.pop_back(); discovery[v] = 0;
            if (u == v)
                break;
        }
    }
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        int u, v, p;
        G.assign(n, vi());
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> p;
            u--, v--;
            G[u].push_back(v);
            if (p == 2)
                G[v].push_back(u);
        }
        SCC = tick = 0;
        num.assign(n, -1);
        low.assign(n, 0);
        discovery.assign(n, 0);
        for (int i = 0; i < n; ++i)
            if (num[i] == -1)
                tarjan(i);

        cout << (SCC == 1) << '\n';
    }
}
