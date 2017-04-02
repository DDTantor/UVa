#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MAX_N = 1000000;

int main()
{
    vector<ll> sieve(MAX_N, 0);
    vector<ll> P(MAX_N);
    ll n = 0, N;
    for (ll i = 2; i < MAX_N; ++i)
    {
        if (!sieve[i])
        {
            P[n++] = i;
            for (ll j = i; j < MAX_N; j += i)
                sieve[j]++;
        } 
    }
    
    while (cin >> N, N)
    {
        ll cnt = 0;
        for (ll i = 0; P[i] <= N && i < n; ++i)
            cnt += !(N % P[i]);
            
        cout << N << " : " << cnt << '\n';
    }
}
