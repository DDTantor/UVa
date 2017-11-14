#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll Primes, IsPrime;

void Sieve(ll bound)
{
    IsPrime.assign(bound, 1);
    IsPrime[0] = IsPrime[1] = 0;
    Primes.push_back(1);
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

int n, c;

int main()
{
    ios::sync_with_stdio(false);
    Sieve(1000);
    while (cin >> n >> c)
    {
        cout << n << ' '  << c << ':';
        int cnt = count_if(Primes.begin(), Primes.end(), [](int a){return a <= n;});
        if (cnt & 1)
            c = c * 2 - 1;
        else
            c *= 2;

        c = min(c, cnt);
        for (int i = cnt / 2 - c / 2, j = 0; j < c; ++i, ++j)
            cout << ' ' << Primes[i];

        cout << "\n\n";
    }
}
