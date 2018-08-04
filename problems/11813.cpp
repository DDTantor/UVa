#include <numeric>
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <functional>
#include <cstring>
#include <algorithm>

using namespace std;

typedef tuple<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m, s, t, dp[11][1 << 11];
vi C;
vvi D;
vvii G;

void dijkstra(int id)
{
    priority_queue<ii, vii, greater<ii> > PQ;
    PQ.emplace(0, C[id]);
    D[id][C[id]] = 0;
    while (!PQ.empty())
    {
        int d, u;
        tie(d, u) = PQ.top(); PQ.pop();
        if (d > D[id][u])
            continue;
        
        for (ii p : G[u])
        {
            int dist, v;
            tie(dist, v) = p;
            if (D[id][v] > D[id][u] + dist)
                D[id][v] = D[id][u] + dist, PQ.emplace(D[id][v], v);
        }
    }
}

int tsp(int id, int mask)
{
    if (mask == (1 << s) - 1)
        return D[id][0];
    
    if (dp[id][mask] != -1)
        return dp[id][mask];

    int res = 1e9;
    for (int i = 0; i < s; ++i)
        if (id != i && !(mask & (1 << i)))
            res = min(res, D[id][C[i]] + tsp(i, mask | (1 << i)));

    return dp[id][mask] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie();
    cin >> t;
    while (cin >> n >> m, t--)
    {
        memset(dp, -1, sizeof(dp));
        G.assign(n, vii());
        for (int i = 0; i < m; ++i)
        {
            int a, b, d;
            cin >> a >> b >> d;
            G[a].emplace_back(d, b);
            G[b].emplace_back(d, a);
        }

        cin >> s;
        ++s;
        D.assign(s, vi(n, 1e9));
        C.assign(s, 0);
        dijkstra(0);
        for (int i = 1; i < s; ++i)
            cin >> C[i], dijkstra(i);
        
        cout << tsp(0, 1) << '\n';
    }
}
