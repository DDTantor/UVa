#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <tuple>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<bool> vb;

int main()
{
    int n, u, v, c = 1;
    while (cin >> n, n)
    {
        map<int, vector<int> > G;
        for (int i = 0; i < n; ++i)
        {
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        int start, life, l;
        while (cin >> start >> life, start || life)
        {
            
            queue<ii> Q;
            Q.emplace(0, start);
            map<int, int> D;
            int cnt = 0;
            D[start] = 0;
            if (G.find(start) != G.end())
            {
                while (!Q.empty())
                {
                    tie(l, v) = Q.front(); Q.pop();
                        for (int e : G[v])
                            if (D.find(e) == D.end())
                                D[e] = l + 1, Q.emplace(l + 1, e);
                }
                for (auto it : D)
                    if (it.second > life)
                        cnt++;
                
                cnt += G.size() - D.size();
            }
            else
                cnt = G.size();
            cout << "Case " << c++ << ": " << cnt << " nodes not reachable from node " << start << " with TTL = " << life << ".\n";
        }
    }
}
