#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n, i, j, a;
    while (cin >> n, n)
    {
        vvi G(n + 1);
        while (cin >> i, i)
            while (cin >> j, j)
                G[i].push_back(j);
        
        cin >> a;
        while (a--)
        {
            int u, cnt = n;
            cin >> u;
            int B[101] = {};
            queue<int> Q;
            Q.push(u);
            while (!Q.empty())
            {
                u = Q.front();
                Q.pop();
                for (int v : G[u])
                {
                    if (!B[v])
                        Q.push(v), cnt--;
                    B[v] = true;
                }
            }
            cout << cnt;
            for (int i = 1; i <= n; ++i)
                if (!B[i])
                    cout << ' ' << i;
            cout << '\n';
        }
        
    }
}
