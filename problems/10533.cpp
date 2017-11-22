#include <iostream>

using namespace std;

typedef long long ll;

const ll maxn = 1000001;
ll sol[maxn], isprime[maxn];

ll sum(ll n)
{
    ll sum = 0;
    while (n)
        sum += n % 10, n /= 10;
    
    return sum;
}

int main()
{
    isprime[0] = isprime[1] = 1;
    for (ll i = 2; i < maxn; ++i)
        if (!isprime[i])
            for (ll j = i * i; j < maxn; j += i)
                isprime[j] = 1;
    
    for (int i = 1; i < maxn - 1; ++i)
        sol[i] = sol[i - 1] + (!isprime[i] && !isprime[sum(i)]);

    ll a, b, n;
    cin >> n;
    while (cin >> a >> b, n--)
        cout << sol[b] - sol[a - 1] << '\n';
}
