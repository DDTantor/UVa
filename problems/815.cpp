#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int main()
{
    int m, n, G[900], L, c = 1;
    while (cin >> m >> n, m || n)
    {
        for (int i = 0; i < m * n; ++i)
            cin >> G[i];
            
        cin >> L;
        sort(G, G + m * n);
        int i, b = 100, h = G[0];
        for (i = 1; i < m * n && L  - b * (G[i] - G[i - 1]) > 0; ++i)
        {
            h += G[i] - G[i - 1];
            L -= b * (G[i] - G[i - 1]);
            b += 100;
        }
        cout << fixed << setprecision(2);
        cout << "Region " << c++ << '\n';
        cout << "Water level is " << h + (double)L / b << " meters.\n";
        cout << 100 * (double)i / (m * n) << " percent of the region is under water.\n\n"; 
    }
}
