#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{

    ll a, b;
    while (cin >> a >> b, a || b)
    {
        if (a > b)
            swap(a, b);
        int m = 1, mi = 0;
        for (ll i = a; i <= b; ++i)
        {
            ll time = 0;
            ll n = i;
            do
            {
                if (n % 2)
                    n = 3 * n + 1;
                else
                    n /= 2;
                time++;
                
            }while (n != 1);
            if (time > m)
                m = time, mi = i;
        }
        cout << "Between " << a << " and " << b << ", " << mi << " generates the longest sequence of " << m << " values.\n";
    }
}
