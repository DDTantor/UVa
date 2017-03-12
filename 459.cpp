#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;

void dfs(int u, const vvi &G, vb &visited)
{
    visited[u] = true;
    for (auto v : G[u])
        if (!visited[v])
            dfs(v, G, visited);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        char c;
        cin >> c;
        int n = c - 'A' + 1;
        
        vvi G(n);
        vb visited(n, false);
        cin.ignore();
        while (getline(cin, s), !s.empty())
        {
            G[s[1] - 'A'].push_back(s[0] - 'A');
            G[s[0] - 'A'].push_back(s[1] - 'A');
        }
        
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (!visited[i])
                cnt++, dfs(i, G, visited);
        
        cout << cnt << '\n';
        if (t)
            cout << '\n';
    }
    
}
