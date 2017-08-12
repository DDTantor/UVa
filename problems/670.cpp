#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi V, X, Y;
vvi G;

int Aug(vi& I, vi& M, int u)
{
    if (V[u])
        return 0;
        
    V[u] = true;
    for (int v : G[u])
    {
        if (M[v] == -1 || Aug(I, M, M[v]))
        {
            M[v] = u;
            I[u] = v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t, m, n;
    cin >> t;
    while (cin >> m >> n, t--)
    {
        X.assign(m + n, 0);
        Y.assign(m + n, 0);
        G.assign(m + n, vi());
        for (int i = 0; i < m + n; ++i)
            cin >> X[i] >> Y[i];
            
        for (int i = 1; i < m; ++i)
        {
            double d = hypot(X[i] - X[i - 1], Y[i] - Y[i - 1]);
            for (int j = 0; j < n; ++j)
            {
                double d1 = hypot(X[i - 1] - X[j + m], Y[i - 1] - Y[j + m]);
                double d2 = hypot(X[i] - X[j + m], Y[i] - Y[j + m]);
                if (2 * d >= d1 + d2)
                    G[i - 1].push_back(j + m);
            }
        }
        int MCBM = 0;
        vi M(n + m, -1);
        vi I(n + m, -1);
        for (int i = 0; i < m; ++i)
        {
            V.assign(m, 0);
            MCBM += Aug(I, M, i);
        }
        
        cout << MCBM + m << '\n';
        for (int i = 0; i < m - 1; ++i)
        {
            cout << X[i] << ' ' << Y[i] << ' ';
            if (I[i] != -1)
                cout << X[I[i]] << ' ' << Y[I[i]] << ' ';
        }
        cout << X[m - 1] << ' ' << Y[m - 1] << '\n';
        if (t)
			cout << '\n';
    }
}
