#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool f(string a, string b)
{
    if (a.size() != b.size())
        return false;
    
    int cnt = 0;
    for (int i = 0; i < a.size(); ++i)
        cnt += a[i] != b[i];

    return cnt == 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vs W;
        unordered_map<string, int> M;
        string s, p;
        while (cin >> s, s != "*")
            M.emplace(s, W.size()), W.push_back(s);

        int n = W.size();
        vvi G(n, vi(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] = (i == j? 0 : f(W[i], W[j])? 1 : 1e9);

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
        
        cin.ignore();
        while (cin.peek() != EOF && cin.peek() != '\n')
        {
            cin >> s >> p;
            int u = M[s], v = M[p];
            cout << s << ' ' << p << ' ' << G[u][v] << '\n';
            cin.ignore();
        }

        if (t) cout << '\n';
    }
}
