#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int G[100][100], n, t, c = 1;

void dfs(int u, vi &visited)
{
    visited[u] = true;
    for (int v = 0; v < n; ++v)
        if (G[u][v] && !visited[v])
            dfs(v, visited);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cout << "Case " << c++ << ":\n";
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> G[i][j];
        
        vi perma(n, 0);
        dfs(0, perma);
        vvi visited(n);
        visited[0].resize(n);        
        for (int i = 1; i < n; ++i)
        {
            visited[i].resize(n);
            visited[i][i] = 1   ;
            dfs(0, visited[i]);
        }
        
        for (int i = 0; i < n; ++i)
        {
            cout << '+';
            for (int j = 0; j < 2 * n - 1; ++j)
                cout << '-';
            cout << "+\n";
            for (int j = 0; j < n; ++j)
            {
                cout << '|';
                if (!perma[j])
                    cout << 'N';
                else if (!visited[i][j] || i == j)
                    cout << 'Y';
                else
                    cout << 'N';
            }
            cout << "|\n";
        }
        cout << '+';
        for (int i = 0; i < 2 * n - 1; ++i)
            cout << '-';
            
        cout << "+\n";
    }
}
