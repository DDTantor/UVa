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

bool squarefree(ll n)
{
    for (int i = 2; i * i <= n; ++i)
        if (!(n % (i * i)))
            return false;

    return true;
}

bool cond(ll n)
{
    for (int i = 0; Primes[i] <= n && i < Primes.size(); ++i)
        if (!(n % Primes[i]) && ((n - 1) % (Primes[i] - 1)))
            return false;
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    Sieve(65000);
    ll n;
    while (cin >> n, n)
    {
        if (cond(n) && squarefree(n) && !IsPrime[n])
            cout << "The number " << n << " is a Carmichael number.\n";
        else
            cout << n << " is normal.\n";
    }
}
