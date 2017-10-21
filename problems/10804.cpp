#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

#define eps 1e-9

typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<int> vi;
typedef vector<vi> vvi;

int n, m, k, cs = 0;
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

bool valid(double p, dd t1, dd t2)
{
    return hypot(t1.first - t2.first, t1.second - t2.second) <= p;
}

int main()
{
    int t;
    cin >> t;
    while (cin >> m >> n >> k, t--)
    {
        vdd P, H;
        
        cout << "Case #" << ++cs << ":\n";
        double x, y;
        
        for (int i = 0; i < m; ++i)
            cin >> x >> y, P.emplace_back(x, y);

        for (int i = 0; i < n; ++i)
            cin >> x >> y, H.emplace_back(x, y);

        if (m - k <= n)
        {
            double lo = 0, hi = 1e9, res = 0;
            while (fabs(hi - lo) > eps)
            {
                double mid = (hi + lo) / 2.0;
                G.assign(n + m, vi());
                M.assign(n + m, -1);
                for (int i = 0; i < m; ++i)
                    for (int j = 0; j < n; ++j)
                        if (valid(mid, P[i], H[j]))
                            G[i].push_back(j + m);

                int MCBM = 0;
                for (int i = 0; i < m; ++i)
                {
                    V.assign(m, 0);
                    MCBM += Aug(M, i);
                }
                
                (MCBM >= m - k? hi : lo) = mid;
                res = mid;
            }

            cout << fixed << setprecision(3) << res << "\n\n";
        }
        else
            cout << "Too bad.\n\n";
    }
}
