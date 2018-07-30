#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <numeric>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
	
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
	
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

vvi G;
vi discovery, num, low, S, W;
int tick, n, m, t, V[1000][1000], res;

void tarjan(int u, UF& C)
{
    low[u] = num[u] = tick++;
    S.push_back(u);
    discovery[u] = 1;
    for (int v : G[u])
    {
        if (num[v] == -1)
            tarjan(v, C);
        
        if (discovery[v])
            low[u] = min(low[u], low[v]);
    }
    
    if (low[u] == num[u])
    {
        int cnt = 0;
        while (true)
        {
            ++cnt;
            int v = S.back(); S.pop_back(); discovery[v] = 0;
            if (u == v)
                break;

            C.u(u, v);
        }

        W[C.f(u)] = cnt;
        res = max(res, cnt);
    }
}

void TopSort(int u, vvi& M, vi& discovery)
{
    discovery[u] = 1;
    for (int v : M[u])
        if (!discovery[v])
            TopSort(v, M, discovery);

    S.push_back(u);
}

int LongestPath(vvi& M, UF& C)
{
    discovery.assign(n, 0);
    S.clear();
    for (int i = 0; i < n; ++i)
        if (!discovery[C.f(i)])
            TopSort(C.f(i), M, discovery);

    vi dist(n, 0);
    
    for (auto it = S.rbegin(); it != S.rend(); ++it)
    {
        if (!dist[*it])
            dist[*it] = W[*it];
                
        for (int v : M[*it])
            dist[v] = max(dist[v], dist[*it] + W[v]), res = max(dist[v], res);
    }
    
    return res;
}

int main()
{
    cin >> t;
    while (cin >> n >> m, t--)
    {
        vvi M(n);
        UF C(n);
        memset(V, 0, sizeof(V));
        G.assign(n, vi());
        tick = res = 0;
        num.assign(n, -1);
        low.assign(n, 0);
        W.assign(n, 0);
        S.clear();
        discovery.assign(n, 0);

        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v, --u, --v;
            G[u].push_back(v);
        }
        
        for (int i = 0; i < n; ++i)
            if (num[i] == -1)
                tarjan(i, C);

        for (int u = 0; u < n; ++u)
            for (int v : G[u])
                if (!C.s(u, v) && !V[C.f(u)][C.f(v)])
                    M[C.f(u)].push_back(C.f(v));

        cout << LongestPath(M, C) << '\n';
    }
}
