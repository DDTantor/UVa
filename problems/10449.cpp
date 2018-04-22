#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

typedef long long ll;
typedef tuple<ll, ll, ll> iii;
typedef vector<iii> viii;
typedef vector<ll> vi;

const int maxn = 200;
vi B, D;
int n, m, cs = 1, q, e;
viii G;

ll cube(ll a)
{
    return a * a * a;
}   

void BF()
{
    D.assign(maxn, 1e9);
    D[0] = 0;
    int u, v, w;
    for (int k = 0; k < n - 1; ++k)
    {
        for (iii e : G)
        {
            tie(u, v, w) = e;
            if (D[v] > D[u] + w && D[u] != 1e9)
                D[v] = D[u] + w;
        }
    }

    for (iii e : G)
    {
        tie(u, v, w) = e;
        if (D[v] > D[u] + w && D[u] != 1e9)
            D[v] = -1e9;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n)
    {
        B.assign(n, 0);
        G.clear();
        for (int i = 0; i < n; ++i)
            cin >> B[i];
        
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            int u, v;
            cin >> u >> v, --u, --v;
            G.emplace_back(u, v, cube(B[v] - B[u]));
        }

        BF();
        cin >> q;
        cout << "Set #" << cs++ << '\n';
        while (q--)
        {
            cin >> e, --e;
            if (e < 0 || D[e] < 3 || D[e] == 1e9)
                cout << "?\n";
            else
                cout << D[e] << '\n';
        }
    }
}
