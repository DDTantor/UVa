#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define inf 1e9

int s, t, R[202][202], n, u, v, b, d, w, m;
vector<vector<int> > G;
vector<int> P;


void add(int a, int b, int w)
{
    R[a][b] += w;
    G[a].push_back(b);
    G[b].push_back(a);
}

bool ap()
{
    P.assign(2 * n + 2, -1);
    queue<int> Q;
    Q.push(s);
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == t)
            return true;

        for (int x : G[k])
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }

    return false;
}

int main()
{
    while (cin >> n)
    {
        memset(R, 0, sizeof(R));
        G.assign(2 * n + 2, vector<int>());
        s = 2 * n; t = 2 * n + 1;
        for (int i = 0; i < n; ++i)
            cin >> w, add(i, i + n, w);

        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> u >> v >> w, add(u - 1 + n, v - 1, w);

        cin >> b >> d;
        for (int i = 0; i < b + d; ++i)
            cin >> u, i < b? add(s, u - 1, inf) : add(u - 1 + n, t, inf);

        int flow = 0;
        while (ap())
        {
            int aug = inf;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);
            
            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            flow += aug;
        }

        cout << flow << '\n';
    }
}
