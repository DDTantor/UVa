#include <iostream>
#include <functional>
#include <queue>
#include <tuple>
#include <vector>
#include <iomanip>

using namespace std;

#define inf 1e9

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef vector<viii> vviii;
typedef vector<double> vi;

int V, E, s, t;
vviii G;
vi P, D;

double dijkstra(double bound)
{
    D.assign(V, inf);
    P.assign(V, -1);
    priority_queue<ii, vii, greater<ii> > PQ;
    D[s] = 0;
    PQ.emplace(0, s);
    while (!PQ.empty())
    {
        int w, u, v, d, c;
        tie(w, u) = PQ.top(); PQ.pop();
        if (w > D[u])
            continue;

        for (iii a : G[u])
        {
            tie(d, c, v) = a;
            if (c <= bound && D[v] > D[u] + d)
                D[v] = D[u] + d, PQ.emplace(D[v], v), P[v] = u;
        }
    }
    
    return D[t];
}

void Print(int x)
{
    if (P[x] == -1)
        return;

    Print(P[x]);
    cout << ' ' << x + 1;
}

int main()
{
    while (cin >> V >> E >> s >> t)
    {
        --s, --t;
        G.assign(V, viii());
        for (int i = 0; i < E; ++i)
        {
            int u, v;
            double c, w;
            cin >> u >> v >> c >> w;
            --u, --v;
            G[u].emplace_back(10 * w, 10 * c, v);
            G[v].emplace_back(10 * w, 10 * c, u);
        }

        int temp;
        for (temp = 200; temp <= 500; ++temp)
        {
            double res = dijkstra(temp);
            if (res != inf)
                break;
        }
        
        cout << s + 1;
        Print(t);
        cout << '\n' << fixed << setprecision(1) << D[t] / 10.0 << ' ' << temp / 10.0 << '\n';
        
    }
}
