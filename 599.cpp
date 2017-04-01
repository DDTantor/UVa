#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;


int cnt, n, tree, acorn;
vi B;
vvi G;

void dfs(int u)
{
    B[u] = 1;
    for (int v : G[u])
        if (B[v] == 0)
            dfs(v);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        G.clear(), B.clear();
        G.resize(26); B.assign(26, -1);
        while (cin >> s, s[0] != '*')
        {
            G[s[1] - 'A'].push_back(s[3] - 'A');
            G[s[3] - 'A'].push_back(s[1] - 'A');
        }
        
        cin >> s;
        n = (s.size() + 1) / 2;
        
        for (int i = 0; i < n; ++i)
            B[s[2 * i] - 'A'] = 0;
            
        tree = acorn = 0;
        
        for (int i = 0; i < G.size(); ++i)
        {
            if (B[i] == 0)
            {
                if (G[i].empty())
                    acorn++, B[i] = 1;
                else
                    tree++, dfs(i);
            }
        }
        cout << "There are " << tree << " tree(s) and " << acorn << " acorn(s).\n";
    }
}
