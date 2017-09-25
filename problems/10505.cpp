#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int t, n, C[200], k, u, v, G[200][200], b, w;

int main()
{
    int t;
    cin >> t;
    while (cin >> n, t--)
    {
        memset(G, 0, sizeof(G));
        memset(C, 0, sizeof(C));
        for (u = 0; u < n; ++u)
        {
            cin >> k;
            for (int i = 0; i < k; ++i)
            {
                cin >> v;
                v--;
                if (v < n)
                    G[u][v] = G[v][u] = 1;
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            if (!C[i])
            {
                b = w = 0;
                bool flag = true;
                queue<int> Q;
                Q.push(i);
                C[i] = 1, w++;
                while (!Q.empty())
                {
                    u = Q.front();
                    Q.pop();
                    for (v = 0; v < n; ++v)
                    {
                        if (G[u][v] && !C[v])
                            C[v] = -C[u], Q.push(v), (C[v] == 1? w : b) += 1;
                        else if (G[u][v] && C[v] == C[u])
                            flag = false;
                    }
                }
                if (flag)
                    res += max(b, w);
            }
        }

        cout << res << '\n';
    }
}
