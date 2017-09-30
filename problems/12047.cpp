#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;

#define inf 1e9

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

int T, n, m, u, v, w;

void dijkstra(const vvii& G, int s, vi& D)
{
    priority_queue<ii, vii, greater<ii> > PQ;
    PQ.emplace(0, s);
    D[s] = 0;
    while (!PQ.empty())
    {
        tie(w, u) = PQ.top(); PQ.pop();
        if (w > D[u])
            continue;
        for (ii t : G[u])
            if (D[u] + t.first < D[t.second])
                D[t.second] = D[u] + t.first, PQ.emplace(D[t.second], t.second);
    }
}

int main()
{
    int s, t, p; 
    cin >> T;
    while (cin >> n >> m >> s >> t >> p, T--)
    {
        s--, t--;
        vvii G1(n), G2(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w;
            G1[--u].emplace_back(w, --v);
            G2[v].emplace_back(w, u);
        }
        vi D1(n, inf), D2(n, inf);
        dijkstra(G1, s, D1);
        dijkstra(G2, t, D2);
        int best = -1;
        for (int i = 0; i < n; ++i)
            for (ii t : G1[i])
                if (D1[i] + D2[t.second] + t.first <= p)
                    best = max(best, t.first);
            
        cout << best << '\n';
    }
}
