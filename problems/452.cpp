#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

#define inf 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

string s;
int n, t, m;
char c;
vi D, V, sol, C;
vvi G;

void dfs(int u)
{
    V[u] = 1;
    for (int v : G[u])
        if (V[v])
            dfs(v);
    
    sol.push_back(u);
}

int main()
{
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        sol.clear();
        G.assign(27, vi());
        V.assign(27, -1);
        C.assign(27, 0);
        D.assign(27, 0);
        m = 0;
        while (getline(cin, s), !s.empty())
        {
            string a;
            istringstream iss(s);
            iss >> c >> n >> a;
            V[c - 'A'] = 0;
            C[c - 'A'] = -n;
            m = min(m , -n);
            if (a.empty())
                D[c - 'A'] = -n;
            for (auto i : a)
                G[i - 'A'].push_back(c - 'A');
        }
        for (int i = 0; i < 27; ++i)
            if (V[i] == 0)
                dfs(i);

        for (int i : sol)
            for (int j : G[i])
                if (D[i] + C[j] < D[j])
                    D[j] = D[i] + C[j], m = min(m, D[j]);
        
        cout << -m << '\n';
        if (t)
            cout << '\n';
    }
}
