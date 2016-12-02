#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;

int V, E;

bool Color(vii G, vi C)
{
    queue<int> Q;
    Q.push(0);
    C[0] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int v : G[u])
        {
            if (!C[v])
                C[v] = -C[u], Q.push(v);
            else if (C[v] == C[u])
                return false;
        }
    }
    return true;
}

int main()
{
    while (cin >> V, V)
    {
        cin >> E;
        vii G(V);
        vi C(V, 0);
        for (int i = 0; i < E; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        if (!Color(G, C))
            cout << "NOT ";
        cout << "BICOLORABLE.\n";
    }
}
