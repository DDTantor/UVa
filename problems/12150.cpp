#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n, P[1000], a, b, fl;
    while (cin >> n, n)
    {
        memset(P, -1, sizeof(P));
        fl = 1;
        for (int i = 0; i < n && cin >> a >> b; ++i)
            if (fl &= i + b >= 0 && i + b < n && P[i + b] == -1)
                P[i + b] = a;
            
        if (fl)
        {
            for (int i = 0; i < n; ++i)
            {
                if (i)
                    cout << ' ';
                
                cout << P[i];
            }
        }
        else
            cout << -1;
        
        cout << '\n';
    }
}
