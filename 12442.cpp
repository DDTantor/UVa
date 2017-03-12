#include <iostream>
#include <vector>


using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi Max, G;
vb visited;

int dfs(int u)
{
    int cnt = 0;
    visited[u] = true;
    if (G[u] != -1 && !visited[G[u]])
        cnt += 1 + dfs(G[u]);
    
    visited[u] = false;
    return Max[u] = cnt; 
}
int main()
{
    int t, n, c = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        G.assign(n, -1);
        Max.assign(n, -1);
        visited.assign(n, false);
        for (int i = 0; i < n; ++i)
        {
            int u, v;
            cin >> u >> v;
            G[u - 1] = v - 1;
        }
        
        int max = 0, id;
        for (int u = 0; u < n && max < n; ++u)
        {
            if (Max[u] == -1) dfs(u);
            if (Max[u] > max)
                id = u, max = Max[u];
        }
        
        cout << "Case " << c++ << ": " << id + 1<< '\n';
    }
}
