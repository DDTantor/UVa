#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef vector<vs> vvs;

int n;
vi V, M;
vvi G;
vvs S;

void turn(int i, int j)
{
    transform(S[i][j].begin(), S[i][j].end(), S[i][j].begin(), ::tolower);
    S[i][j][0] = toupper(S[i][j][0]);
}

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

int main()
{
    int t, cs = 0, n, k;
    cin >> t;
    while (cin >> n, t--)
    {
        cout << "Case #" << ++cs << ":\n";
        G.assign(n + 26, vi());
        S.assign(n, vs());
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            S[i].resize(k);
            for (int j = 0; j < k; ++j)
                cin >> S[i][j], turn(i, j), G[S[i][j][0] - 'A'].push_back(26 + i);

        }
        
        M.assign(n + 26, -1);
        int MCBM = 0;
        for (int i = 0; i < 26; ++i)
            V.assign(26, 0), MCBM += Aug(M, i);

        string res[26];
        for (int i = 26; i < 26 + n; ++i)
            for (string s : S[i - 26])
                if ('A' + M[i] == s[0])
                    res[M[i]] = s;
            
        for (int i = 0; i < n; ++i)
            cout << res[i] << '\n';
    }
}
