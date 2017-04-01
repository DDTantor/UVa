#include <iostream>

using namespace std;

int main()
{
    int m, n, t;
    cin >> t;
    while (cin >> n >> m, t--)
    {
        int a, flag = 1, E[820] = {}, G[41][820];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a, E[j] += a, G[i][j] = a;
        
        for (int i = 0; i < m; ++i)
            flag &= (E[i] == 2);
            
        for (int i = 0; i < m; ++i)
            for (int j = i + 1; j < m; ++j)
                for (int k = 0, cnt = 0; k < n; ++k, flag &= (cnt < 2))
                    cnt += (G[k][i] == 1 && G[k][i] == G[k][j]);
        
        cout << (flag? "Yes\n" : "No\n");
    }
    
}
