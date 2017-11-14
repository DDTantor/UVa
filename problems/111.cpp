#include <iostream>
#include <vector>

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
    Sieve(1 << 15);
    ll res[1 << 15] = {0}, n;
    for (int i = 0; i < Primes.size(); ++i)
        for (int j = i; j < Primes.size() && Primes[i] + Primes[j] <= (1 << 15); ++j)
            ++res[Primes[i] + Primes[j]];

    while (cin >> n, n)
        cout << res[n] << '\n';
}
