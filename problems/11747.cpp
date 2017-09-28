#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int n, m;
vi V;
vvii G;
priority_queue<ii> PQ;
vi W;

void process(int u)
{
    V[u] = 1;
    for (ii v : G[u])
        if (!V[v.first])
            PQ.emplace(-v.second, -v.first);
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        G.assign(n, vii());
        W.clear();
        for (int i = 0; i < m; ++i)
        {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
            W.push_back(w);
        }

        V.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (!V[i])
            {
                process(i);
                while (!PQ.empty())
                {
                    ii f = PQ.top(); PQ.pop();
                    int u = -f.second, w = -f.first;
                    if (!V[u])
                        W.erase(find(W.begin(), W.end(), w)), process(u);
                }
            }
        }
        sort(W.begin(), W.end());
        if (!W.empty())
            for (int i = 0; i < W.size(); ++i)
                cout << W[i] << (i == W.size() - 1? '\n' : ' ');
        else
            cout << "forest\n";
    }
}
