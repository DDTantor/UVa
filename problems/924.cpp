#include <queue>
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int e, n, t, u, v, s, w, d;
vvi G;

int main()
{
    cin >> e;
    G.assign(e, vi());
    for (int i = 0; i < e; ++i)
    {
        cin >> n;
        for (int j = 0; j < n; ++j)
            cin >> u, G[i].push_back(u);
    }

    cin >> t;
    while (t--)
    {
        cin >> s;
        queue<ii> Q;
        vi D(e, 0), V(e, 0);
        Q.emplace(s, 0);
        while (!Q.empty())
        {
            tie(u, w) = Q.front(); Q.pop();
            if (!V[u])
            {
                D[w]++;
                V[u] = true;
                for (int v : G[u])
                    Q.emplace(v, w + 1);
            }   
        }
        w = d = 0;
        for (int i = 1; i < e; ++i)
            if (w < D[i])
                w = D[i], d = i;
        if (w)
            cout << w << ' ' << d << '\n';
        else
            cout << "0\n";
    }
}
