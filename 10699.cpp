#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAX_N = 1000000;

int main()
{
    vector<ll> sieve(MAX_N, 0);
    ll n = 0, N;
    for (ll i = 2; i < MAX_N; ++i)
        if (!sieve[i])
            for (ll j = i; j < MAX_N; j += i)
                sieve[j]++;
    
    
    while (cin >> N, N)
    {
        ll cnt = 0;
        cout << N << " : " << sieve[N] << '\n';
    }
}
