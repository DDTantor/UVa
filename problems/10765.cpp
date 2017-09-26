#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int, int> ii;
typedef vector<bool> vb;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int tick, n, m;
vi discovery, bridges, articulation;
vvi G;

bool cmp(const ii &a, const ii &b)
{
    if (a.first > b.first)
        return true;
    if (a.first == b.first && a.second < b.second)
        return true;
    return false;
}

int dfs(int x, int dad)
{
    discovery[x] = ++tick;
    int low = discovery[x];

    articulation[x] = 1;
    int children = 0;
    for (int y : G[x])
    {
        if (y == dad)
            continue;
        if (discovery[y] < 0)
        {
            ++children;
            int w = dfs(y, x);
            if (w >= discovery[x])
                articulation[x]++;
            low = min(low, w);
        }
        else
            low = min(low, discovery[y]);
    }
    if (dad == -1)
        articulation[x] = children;
    
    return low;
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        G.assign(n, vi());
        discovery.assign(n, -1);
        bridges.assign(n, 0);
        articulation.assign(n, 0);
        int u, v;
        while (cin >> u >> v, u != -1 && v != -1)
            G[u].push_back(v), G[v].push_back(u);

        tick = 1;
        for (int i = 0; i < n; ++i)
            if (discovery[i] == -1)
                dfs(i, -1);

        vii B;
        for (int i = 0; i < n; ++i)
            B.push_back(ii(articulation[i], i));
        
        sort(B.begin(), B.end(), cmp);
        for (int i = 0; i < m; ++i)
            cout << B[i].second << ' ' << B[i].first << '\n';
        cout << '\n';
    }
}
