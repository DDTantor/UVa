#include <iostream>

using namespace std;

int main()
{
    int n, t, p, P[100];
    cin >> t;
    while (cin >> n >> p, t--)
    {
        for (int i = 0; i < p; ++i)
            cin >> P[i];
        
        int h = 0;
        bool flag;    
        for (int i = 1; i <= n; ++i)
        {
            if (i % 7 == 6 || i % 7 == 0)
                continue;
            flag = false;
            for (int j = 0; j < p; ++j)
                if (!(i % P[j]))
                    flag = true;
            
            if (flag)
                h++;
        }
        cout << h << '\n';
    }
}
