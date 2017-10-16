#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll Primes, IsPrime;
int n, k, dp[1121][15];

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
    Sieve(1121);
    dp[0][0] = 1;
    for (int i : Primes)
        for (int j = 1120; j >= i; --j)
            for (int k = 14; k >= 1; --k)
                dp[j][k] += dp[j - i][k - 1];
    
    while (cin >> n >> k, n || k)
        cout << dp[n][k] << '\n';
}
