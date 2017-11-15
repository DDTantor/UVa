#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const ll maxn = 5000001;
ll dp[maxn], sum[maxn];
bool isprime[maxn];

void Sieve()
{
    for (ll i = 2; i < maxn; ++i)
    {
        if (!isprime[i])
        {
            sum[i] += i;
            for (ll j = 2 * i; j < maxn; j += i)
                isprime[j] = true, sum[j] += i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    Sieve();
    for (ll i = 2; i < maxn; ++i)
        dp[i] = dp[i - 1] + !isprime[sum[i]];
    
    ll a, b;
    while (cin >> a >> b, a)
        cout << dp[b] - dp[a - 1] << '\n';
}
