#include <algorithm>
#include <iostream>
#include <numeric>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

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

void kruskal(int n, viii& E, vvii& G)
{
    UF uf(n);
    sort(E.begin(), E.end());
    for (auto& t : E)
    {
        int w, a, b;
        tie(w, a, b) = t;
        if (!uf.s(a, b))
            uf.u(a, b), G[a].emplace_back(b, w), G[b].emplace_back(a, w);
    }	
}

int D[100][100];

void dfs(int u, int s, vi& V, vvii& G)
{
    for (ii p : G[u])
    {
        int v, w;
        tie(v, w) = p;
        if (!V[v])
        {
            V[v] = 1, D[s][v] = D[v][s] = max(D[s][u], w);
            dfs(v, s, V, G);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n, m, q, cs = 1, u, v, w;
    while (cin >> n >> m >> q, n + m + q)
    {
        memset(D, 0, sizeof D);
        cout << "Case #" << cs++ << '\n';
        viii E;
        vvii G(n, vii());
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w, --u, --v;
            E.emplace_back(w, u, v);
        }
    
        kruskal(n, E, G);

        for (int i = 0; i < n; ++i)
        {
            vi V(n, 0);
            dfs(i, i, V, G);
        }

        while (q--)
        {
            cin >> u >> v, --u, --v;
            if (D[u][v] == 0)
                cout << "no path\n";
            else
                cout << D[u][v] << '\n';
        }

        cin.ignore();
        if (cin.peek() != '0')
            cout << '\n';
    }
}
