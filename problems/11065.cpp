#include <iostream>

using namespace std;

typedef long long ll;

ll n, m, cnt, best, G[61];

void solve(ll i, ll used, ll d)
{
    if (used == (1LL << n) - 1)
        ++cnt, best = max(best, d);
    else
    {
        for (int j = i; j < n; ++j)
            if (!(used & (1LL << j)))
                solve(j + 1, used | G[j], d + 1);
    }
}

int main()
{
    ll t, u, v;
    cin >> t;
    while (cin >> n >> m, t--)
    {
        for (int i = 0; i < n; ++i)
            G[i] = (1LL << i);

        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v;
            G[u] |= (1LL << v);
            G[v] |= (1LL << u);
        }

        best = cnt = 0;
        solve(0, 0, 0);
        cout << cnt << '\n' << best << endl;
    }  
}
