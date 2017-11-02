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
    Sieve(10000);
    int n = Primes.size(), x;
    vll sum(++n);
    for (int i = 0; i < n; ++i)
        sum[i + 1] = sum[i] + Primes[i];

    while (cin >> x, x != 0)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                cnt += sum[j] - sum[i] == x;

        cout << cnt << '\n';
    }
}
