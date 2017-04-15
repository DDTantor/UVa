#include <iostream>
#include <functional>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;


int main()
{
    int t, n, s, m, tm, u, v, w;
    cin >> t;
    while (cin >> n >> s >> tm >> m, t--)
    {
        vvii G(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> u >> v >> w;
            G[v - 1].emplace_back(w, u - 1);
        }
        vi D(n, INT_MAX);
        D[s - 1] = 0;
        priority_queue<ii, vii, greater<ii> > PQ;
        PQ.emplace(0, s - 1);
        while (!PQ.empty())
        {
            tie(w, u) = PQ.top(); PQ.pop();
            if (w > D[u])
                continue;
            for (auto v : G[u])
                if (D[v.second] > w + v.first)
                    D[v.second] = w + v.first, PQ.emplace(D[v.second], v.second);
        }
        int res = 0;
        for (auto i : D)
            res += (i <= tm);
        cout << res << '\n';
        if (t)
            cout << '\n';
    }
}
