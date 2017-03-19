#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, vol;
    while (cin >> n, n)
    {
        int x1, y1, z1, x2, y2, z2, x11, y11, z11, x12, y12, z12, k;
        cin >> x1 >> y1 >> z1 >> k;
        x2 = x1 + k;
        y2 = y1 + k;
        z2 = z1 + k;
        for (int i = 1; i < n; ++i)
        {
            cin >> x11 >> y11 >> z11 >> k;
            x12 = x11 + k;
            y12 = y11 + k;
            z12 = z11 + k;
            x1 = max(x1, x11);
            y1 = max(y1, y11);
            z1 = max(z1, z11);
            x2 = min(x2, x12);
            y2 = min(y2, y12);
            z2 = min(z2, z12);
        }
        if (x2 <= x1 || y2 <= y1 || z2 <= z1)
            vol = 0;
        else
            vol = (x2 - x1) * (y2 - y1) * (z2 - z1);
            
        cout << vol << '\n';
    }
    
}
