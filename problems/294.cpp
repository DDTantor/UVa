#include <iostream>

using namespace std;

typedef long long ll;

ll numDiv(ll n)
{
    ll res = 1;
    for (ll i = 2; i * i <= n; ++i)
    {
        ll cnt = 1;
        while (!(n % i))
            n /= i, cnt++;
            
        res *= cnt;
    }
    if (n > 1)
        res *= 2;
    return res;
}

int main()
{
    int t;
    cin >> t;
    ll L, U;
    while (cin >> L >> U, t--)
    {
        ll res = 0, best;
        for (ll i = L; i <= U; ++i)
        {
            ll tmp = numDiv(i);
            
            if (tmp > res)
                res = tmp, best = i;
        }
        cout << "Between " << L << " and " << U << ", " << best << " has a maximum of " << res << " divisors.\n";
    }
}
