#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << c++ << ": ";
        int n, M = 0, J = 0;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int c;
            cin >> c;
            M += (c / 30 + 1) * 10;
            J += (c / 60 + 1) * 15;
        }
        int m = min(M, J);
        if (M == m)
            cout << "Mile ";
        if (J == m)
            cout << "Juice ";
        cout << m << '\n';
    }
    
}
