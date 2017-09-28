#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int A[100], B[100], t, n, m, c = 0;
vi V, M;
vvi G;

int Aug(int u)
{
    if (V[u])
        return 0;

    V[u] = true;
    for (int v : G[u])
    {
        if (M[v] == -1 || Aug(M[v]))
        {
            M[v] = u;
            return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        cin >> m;
        for (int i = 0; i < m; ++i)
            cin >> B[i];

        G.assign(m + n, vi());
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (B[j] == 0 || (A[i] && !(B[j] % A[i])))   
                    G[i].push_back(j);
                
        int mcbm = 0;
        M.assign(n + m, -1);
        for (int i = 0; i < n; ++i)
        {
            V.assign(n, 0);
            mcbm += Aug(i);
        }
        cout << "Case " << ++c << ": " << mcbm << '\n';       
    }
}
