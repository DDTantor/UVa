#include <iostream>

using namespace std;

typedef long long ll;

const ll maxn = 100000;
const ll mod = ll(1e9) + 7;

ll Prime[maxn], IsPrime[maxn], p;

void Sieve()
{
    IsPrime[1] = IsPrime[1] = 1;

    for (ll i = 2; i < maxn; ++i)
    {
        if (!IsPrime[i])
        {
            for (ll j = i * i; j < maxn; j += i)
                IsPrime[j] = 1;

            Prime[p++] = i;
        }
    }
}

ll modpow(ll a, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k % 2)
            res = (res * a) % mod;

        a = (a * a) % mod;
        k /= 2;
    }

    return res;
}

ll t, n, m;

int main()
{
    Sieve();
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cin >> m >> n;
        cout << "Case " << t << ": ";
        ll res = m % mod, s = 0, tmp;
        for (int i = 0; i < p && Prime[i] < m ; ++i)
            s = (s + m - Prime[i]) % mod;

        if (n >= 2)
            res = (res + (s * (n - 1)) % mod) % mod;

        
        s = 0;
        for (int i = 1; i < p && Prime[i] + 2 < m; ++i)
            if (!IsPrime[2 + Prime[i]])
                s = (s + m - 2 - Prime[i]) % mod;

        if (n >= 3)
        {
            tmp = ((((n - 1) * (n - 2)) % mod) * modpow(2, mod - 2)) % mod;
            res = (res + 2 * (s * tmp) % mod) % mod;
        }
        
        s = 0;
        for (int i = 1; i < p && Prime[i] + 4 < m; ++i)
            if (!IsPrime[4 + Prime[i]] && !IsPrime[2 + Prime[i]])
                s = (s + m - 4 - Prime[i]) % mod;
        
        if (n >= 4)
        {
            tmp = ((((((n - 1) * (n - 2)) % mod) * (n - 3)) % mod) * modpow(6, mod - 2)) % mod;
            res = (res + (s * tmp) % mod) % mod;
        }
            
        cout << res << '\n';
    }
}
