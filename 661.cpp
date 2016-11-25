#include <iostream>

using namespace std;

int main()
{
    int n, m, c, s = 1;
    int C[20];
    while (cin >> n >> m >> c, n || m || c)
    {
        int b = 0;
        for (int i = 0; i < n; ++i)
            cin >> C[i];
        
        int t = 0, max = 0;
        for (int i = 0; i < m; ++i)
        {
            int d;
            cin >> d;
            d--;
            if (b & (1 << d))
                t -= C[d];
            else
                t += C[d];
            b ^= (1 << d);
            if (t > max)
                max = t;
        }
        cout << "Sequence " << s++ << '\n';
        if (max > c)
            cout << "Fuse was blown.\n";
        else
            cout << "Fuse was not blown.\nMaximal power consumption was " << max << " amperes.\n";
        cout << '\n';
    }
}
