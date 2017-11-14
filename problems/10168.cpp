#include <iostream>
#include <vector>
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

const ll maxn = 10000002;

void solve(ll n)
{
    if (IsPrime[n - 2])
    {
        cout << "2 " << n - 2 << '\n';
        return;
    }
    
    for (int i = 3; i < n; i += 2)
    {
        if (IsPrime[n - i] && IsPrime[i])
        {
            cout << i << " " << n - i << '\n';
            return;
        }
    }
}

int main()
{
    Sieve(maxn);

    ll n;
    while (cin >> n)
    {
        if (n < 8)
            cout << "Impossible.\n";
        else if (n % 2)
            cout << "2 3 ", solve(n - 5);
        else
            cout << "2 2 ", solve(n - 4);
    }
}
