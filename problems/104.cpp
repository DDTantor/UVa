#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

double G[20][20][20];
int n, par[20][20][20], s, num, y, res[20];

int main()
{
    while (cin >> n)
    {
        memset(G, 0, sizeof(G));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                    cin >> G[i][j][0];
                else
                    G[i][j][0] = 1;
                
                par[i][j][0] = j;
            }

        }

        for (int m = 1; m < n; ++m)
            for (int k = 0; k < n; ++k)
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < n; ++j)
                        if (G[i][k][m - 1] * G[k][j][0] > G[i][j][m])
                            G[i][j][m] = G[i][k][m - 1] * G[k][j][0], par[i][j][m] = k;

        s = -1, num = 0;
        for (int m = 0; m < n && s == -1; ++m)
            for (int i = 0; i < n && s == -1; ++i)
                if (G[i][i][m] >= 1.01)
                    num = m, s = i;
        if (s != -1)
        {
            y = s;
            n = num + 1;
            while (num + 1)
            {
                res[num] = y + 1;
                y = par[s][y][num--];
            }
            cout << s + 1;
            for (int i = 0; i < n; ++i)
                cout << ' '  << res[i];
            cout << '\n';
        }
        else
            cout << "no arbitrage sequence exists\n";
      
      
    
        
    }
}
