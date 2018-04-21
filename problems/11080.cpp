#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int b, w;
vvi G;
vi C;

bool check(int i)
{
    b = 1, w = 0;
    queue<int> Q;
    Q.push(i);
    C[i] = 1;
    while (!Q.empty())
    {
        int u = Q.front(); Q.pop();
        for (int v : G[u])
        {
            if (!C[v])
                C[v] = -C[u], Q.push(v), (C[v] == 1? b : w)++;
            else if (C[v] == C[u])
                return false;
        }
    }

    return true;
}

int main()
{
    int t, V, E, u, v;
    cin >> t;
    while (cin >> V >> E, t--)
    {
        G.assign(V, vi());
        for (int i = 0; i < E; ++i)
        {
            cin >> u >> v;
            G[u].push_back(v), G[v].push_back(u);
        }

        bool good = true;
        int res = 0;
        C.assign(V, 0);
        for (int i = 0; i < V; ++i)
            if (!C[i])
                good &= check(i), res += (b && w? min(b, w) : max(b, w));

        if (good)
            cout << res << '\n';
        else
            cout << "-1\n";
    }
}
