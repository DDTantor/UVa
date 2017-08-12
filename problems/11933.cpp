#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    while (cin >> n, n)
    {
        ll r[2] = {}, ind = 0;
        for (ll i = 1; i <= n; i <<= 1)
            if (n & i)
                r[ind++] += i, ind %= 2;
        
        cout << r[0] << ' ' << r[1] << '\n';
    }
    
}
