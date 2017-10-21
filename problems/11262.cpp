#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, p, k, t, x, y;
vi V, M;
vvi G;

int Aug(vi& M, int u)
{
    if (V[u])
        return 0;

    V[u] = true;
    for (int v : G[u])
    {
        if (M[v] == -1 || Aug(M, M[v]))
        {
            M[v] = u;
            return 1;
        }
    }
    
    return 0;
}

bool valid(ii t1, ii t2, int mid)
{
    return hypot(t1.first - t2.first, t1.second - t2.second) <= mid;
}

int main()
{
    int p, k, t, x, y;
    string s;
    cin >> t;
    while (cin >> p >> k, t--)
    {
        vii B, R;
        for (int i = 0; i < p; ++i)
        {
            cin >> x >> y >> s;
            if (s == "blue")
                B.emplace_back(x, y);
            else
                R.emplace_back(x, y);
        }
        n = B.size(); m = R.size();
        if (n >= k && m >= k)
        {
            int lo = 0, hi = 2829, res;
            while (lo != hi)
            {
                int mid = floor((lo + hi) / 2.0);
                G.assign(n + m, vi());
                M.assign(n + m, -1);
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < m; ++j)
                        if (valid(B[i], R[j], mid))
                            G[i].push_back(n + j);
                            
                int MCBM = 0;
                for (int i = 0; i < n; ++i)
                {
                    V.assign(n, 0);
                    MCBM += Aug(M, i);
                }

                if (MCBM >= k)
                    hi = res = mid;
                else
                    lo = res = mid + 1;
            }
            cout << res << '\n';
        }
        else
            cout << "Impossible\n";
    }
}
