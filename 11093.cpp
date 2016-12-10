#include <iostream>

using namespace std;

int main()
{
    int P[100001], n, c = 1, t;
    cin >> t;
    while (cin >> n, t--)
    {
        cout << "Case " << c++ << ": ";
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        
        for (int i = 0; i < n; ++i)
        {   
            int q;
            cin >> q;
            P[i] -= q;
        }
            
        int time = 0, pos = 0, tank = 0, c = 0, s = 0;
        while (s < n && time < 2 * n)
        {
            tank += P[pos];
            pos++, time++, s++;
            pos %= n;
            if (tank < 0)
                tank = 0, c = pos, s = 0;
        }
        if (s == n)
            cout << "Possible from station " << c + 1 << '\n';
        else
            cout << "Not possible\n";
    }
}
