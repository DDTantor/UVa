#include <iostream>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef vector<int> vi;

bool Solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    viii E;
    for (int i = 0; i < m; ++i)
    {
        cin >> u >> v >> w;
        E.emplace_back(u, v, w);
    }
    
    vi D(n, 1000000);
    D[0] = 0;
    
    for (int i = 0; i < n; ++i)
    {
        for (auto t : E)
        {
            tie(u, v, w) = t;
            if (D[u] + w < D[v])
                D[v] = D[u] + w;
        }
    }
    
    for (auto t : E)
    {
        tie(u, v, w) = t;
        if (D[u] + w < D[v])
            return true;
    }
    return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout << (Solve() ? "possible\n" : "not possible\n");    
}
