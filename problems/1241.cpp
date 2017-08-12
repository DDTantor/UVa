#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    int t;
    bitset<1024> c;
    cin >> t;
    while (t--)
    {
        int m, a, n;
        c.set();
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> a;
            c[a - 1] = false;
        }
        
        int res = 0;
        n = 1 << n;
        while (n)
        {
            int ind = 0;
            for (int i = 1; i < n; i += 2)
            {
                res += (c[i] ^ c[i - 1]);
                c[ind++] = (c[i] || c[i - 1]);
            }
            n >>= 1;
        }
        cout << res << endl;
    }
    
}
