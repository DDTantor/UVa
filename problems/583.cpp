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
    int n;
    Sieve(50000);
    while (cin >> n, n)
    {
        cout << n << " = ";
        bool fl = false;
        if (n < 0)
            cout << "-1", n = -n, fl = true;

        int p = 0;
        while (Primes[p] * Primes[p] <= n)
        {
            while (!(n % Primes[p]))
                cout << (fl? " x " : "") << Primes[p], n /= Primes[p], fl = true;
            ++p;
        }

        if (n != 1)
            cout << (fl? " x " : "") << n;
        
        cout << '\n';
    }
}
