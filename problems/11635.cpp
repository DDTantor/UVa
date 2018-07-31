#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

#define inf 1e9

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, h, m;
vvii G;
vi C;
vvi D;

void dijkstra(int id)
{
    D[id].assign(n, inf);
    priority_queue<ii, vii, greater<ii> > PQ;
    PQ.emplace(0, id);
    D[id][id] = 0;
    while (!PQ.empty())
    {
        int d, u;
        tie(d, u) = PQ.top(); PQ.pop();
        if (d > D[id][u])
            continue;

        for (ii p : G[u])
        {
            int v, tm;
            tie(v, tm) = p;
            if (D[id][v] > D[id][u] + tm)
                D[id][v] = D[id][u] + tm, PQ.emplace(D[id][v], v);
        }
    }
}


int bfs()
{
    queue<ii> Q;
    vi V(n);
    Q.emplace(0, 0);
    V[0] = 1;
    while (!Q.empty())
    {
        int u, d;
        tie(u, d) = Q.front(); Q.pop();
        if (u == n - 1)
            return d - 1;
        
        for (int v : C)
            if (D[u][v] <= 600 && !V[v])
                Q.emplace(v, d + 1), V[v] = 1;
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n, n)
    {
        cin >> h;
        C.clear();
        G.assign(n, vii());
        int c;
        C.push_back(0);
        C.push_back(n - 1);
        for (int i = 0; i < h; ++i)
            cin >> c, C.push_back(c - 1);

        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int u, v, t;
            cin >> u >> v >> t, --u, --v;
            G[u].emplace_back(v, t);
            G[v].emplace_back(u, t);
        }
        
        D.assign(n, vi());
        for (int i : C)
            dijkstra(i);
        
        cout << bfs() << '\n';
    }
}   
