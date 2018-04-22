#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

typedef vector<string> vs;
typedef tuple<int, string, char> path;

unordered_map<string, unordered_map<string, vs> > G;
unordered_map<string, map<char, int> > D;
string s, e;
int n, m;

string dijkstra()
{
    D.clear();
    priority_queue<path, vector<path>, greater<path> > PQ;
    PQ.emplace(0, s, '0');
    D[s]['0'] = 0;
    while (!PQ.empty())
    {
        string u;
        char c;
        int d;
        tie(d, u, c) = PQ.top(); PQ.pop();
        
        if (u == e)
            return to_string(d);
        
        if (D[s][c] && D[s][c] < d)
            continue;

        for (auto it : G[u])
        {
            string v = it.first;
            for (string a : it.second)
                if (a[0] != c && (D[v].find(a[0]) == D[v].end() || D[v][a[0]] > D[u][c] + a.size()))
                    D[v][a[0]] = d + a.size(), PQ.emplace(d + a.size(), v, a[0]);
        }
    }
    
    return "impossivel";
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> m, m)
    {
        G.clear();
        string a, b, d;
        cin >> s >> e;
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b >> d;
            G[a][b].push_back(d);
            G[b][a].push_back(d);
        }

        cout << dijkstra() << '\n';
    }
}
