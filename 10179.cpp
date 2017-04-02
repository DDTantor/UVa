#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll n;
    while (cin >> n, n)
    {
        ll res = n;
        for (ll i = 2; i * i <= n; ++i)
        {
            if (!(n % i))
                res -= res / i;
            while (!(n % i))
                n /= i;
        }
        if (n > 1)
            res -= res / n;
            
        cout << res << '\n';
    }
}
