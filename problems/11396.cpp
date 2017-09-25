#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int C[300], n;
vvi G;

bool Color()
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
    while (cin >> n, n)
    {
        int u, v;
        G.assign(n, vi());
        memset(C, 0, sizeof(C));
        while (cin >> u >> v, u || v)
            G[u - 1].push_back(v - 1), G[v - 1].push_back(u - 1);

        if (!Color())
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
