#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll Primes, IsPrime;
ll dp[1000002];
bool V[1000002];

void Sieve(int bound)
{
    IsPrime.assign(bound + 1, 1);
    IsPrime[0] = IsPrime[1] = 0;

    for (ll i = 5; i <= bound; i += 4)
    {
        if (IsPrime[i] && !((i - 1) % 4))
        {    for (ll j = i * i; j <= bound; j += i)
                if (!((j - 1) % 4))
                    IsPrime[j] = 0;

            Primes.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    Sieve(1000001);
    for (int q : Primes)
    {
        for (int p : Primes)
        {
            if (p * q > 1000001)
                break;

            V[p * q] = 1;
        }
    }

    for (int i = 1; i < 1000002; ++i)
        dp[i] = dp[i - 1] + V[i];
    
    int n;
    while (cin >> n, n)
        cout << n << ' ' << dp[n] << endl;
}
