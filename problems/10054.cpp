#include <iostream>
#include <vector>
#include <list>
#include <cstring>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int t, deg[1000], n, c = 0, cnt;
vvii G;

list<int> cyc;

void EulerTour(list<int> :: iterator i, int u)
{
    for (int j = 0; j < G[u].size(); ++j)
    {
        ii v = G[u][j];
        if (v.second)
        {
            G[u][j].second = 0;
            for (int k = 0; k < G[v.first].size(); ++k)
            {
                ii uu = G[v.first][k];
                if (uu.first == u && uu.second)
                {
                    G[v.first][k].second = 0;
                    break;
                }
            }
            EulerTour(cyc.insert(i, u), v.first);
        }
    }
}

int main()
{
    cin >> t;
    while (cin >> n, t--)
    {
        if (c)
            cout << '\n';
        int u, v;
        G.assign(50, vii());
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < n; ++i)
        {
            cin >> u >> v;
            u--, v--;
            G[u].emplace_back(v, 1);
            G[v].emplace_back(u, 1);
            deg[u]++, deg[v]++;
        }
        cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += (deg[i] % 2);
        
        cout << "Case #" << ++c << '\n';
        if (cnt == 0)
        {
            cyc.clear();
            EulerTour(cyc.begin(), u);
            int a = 0;
            for (auto it = cyc.begin(); it != cyc.end(); ++it)
            {
                cout << *it + 1 << ' ';
                if (a++)
                    cout << '\n' << *it + 1 << ' ';
            }
            cout << *cyc.begin() + 1 << '\n';
        }
        else
            cout << "some beads may be lost\n";
        
    }
}
