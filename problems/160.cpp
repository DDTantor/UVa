#include <iostream>
#include <vector>
#include <iomanip>

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
    ios::sync_with_stdio(false);
    Sieve(100);
    int n;
    while (cin >> n, n)
    {
        vll F(Primes.back() + 1, 0);
        for (int i = 2; i <= n; ++i)
        {
            int tmp = i;
            for (int p : Primes)
                while (!(tmp % p))
                    ++F[p], tmp /= p;
        }

        cout << setw(3) << n << "! =";
        for (int i = 0; i < Primes.size() && Primes[i] <= n; ++i)
        {
            int r = 3;
            if (!((i + 1) % 16))
                cout << '\n', r = 9;
            
            cout << setw(r) << F[Primes[i]];
        }
        
        cout << '\n';
    }
}
