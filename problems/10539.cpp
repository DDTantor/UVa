#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll Primes, IsPrime;

void Sieve(ll bound)
{
    IsPrime.assign(bound, 1);
    IsPrime[0] = IsPrime[1] = 0;

    for (ll i = 2; i < bound; ++i)
    {
        if (IsPrime[i])
        {
            for (ll j = i * i; j < bound; j += i)
                IsPrime[j] = 0;

            Primes.push_back(i);
        }
    }
}

int main()
{
    Sieve(1000000);
    vll A;
    for (ll p : Primes)
        for (ll i = p * p; i < ll(1e12); i *= p)
            A.push_back(i);

    sort(A.begin(), A.end());
    int q;
    cin >> q;
    ll a, b;
    while (cin >> a >> b, q--)
        cout << upper_bound(A.begin(), A.end(), b) - lower_bound(A.begin(), A.end(), a) << '\n';
}
