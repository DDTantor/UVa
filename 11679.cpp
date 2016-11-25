#include <iostream>

using namespace std;

int main()
{
    int b, n;
    int B[20];
    while (cin >> b >> n, b || n)
    {
        for (int i = 0; i < b; ++i)
            cin >> B[i];
        
        int d, c, v;
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            cin >> d >> c >> v;
            B[d - 1] -= v;
            B[c - 1] += v;
        }
        for (int i = 0; i < b; ++i)
            if (B[i] < 0)
                flag = false;
        
        if (flag)
            cout << "S\n";
        else
            cout << "N\n";
    }
    
}
