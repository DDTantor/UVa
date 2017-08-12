#include <iostream>

using namespace std;

int main()
{
    int m;
    double d, l, k;
    double C[101];
    while (cin >> m, m > 0)
    {
        cin >> d >> l >> k;
        int prev = 0, a;
        double c;
        cin >> c;
        for (int i = 0; i < k - 1; ++i)
        {
            cin >> c >> a;
            while (prev < a)
                C[prev++] = c;
        }
        cin >> c;
        while (prev < 100)
            C[prev++] = c;
        
        double val = (l + d) * (1 - C[0]);
        int i = 0;
        double mj = l / m;
        while (l > val)
        {
            i++;
            val *= (1 - C[i]);
            l -= mj;
        }
        cout << i << " month";
        if (i != 1)
            cout << 's';
        cout << '\n';
    }
}
    
