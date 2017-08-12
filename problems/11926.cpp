#include <bitset>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m, n || m)
    {
        bool flag = true;
        bitset<1000001> P;
        int s, e, d;
        for (int i = 0; i < n; ++i)
        {
            cin >> s >> e;
            for (int j = s; j < e; ++j)
            {
                flag &= !P[j];
                P.set(j, 1);
            }
            
        }
        
        for (int i = 0; i < m; ++i)
        {
            cin >> s >> e >> d;
            
            while (s <= 1000000)
            {
                for (int j = s; j < e; ++j)
                {
                    flag &= !P[j];
                    P.set(j, 1);
                }
                    
                s += d, e = min(e + d, 1000000);
            } 
        }
        
        if (flag)
            cout << "NO ";
        
        cout << "CONFLICT\n";
    }
}
