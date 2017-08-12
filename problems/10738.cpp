#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

typedef long long ll;

const ll MAX_N = 1000001;

bool SquareFree(ll n)
{
    bool flag = true;
    for (int i = 2; i * i <= n; ++i)
    {
        int cnt = 0;
        while (!(n % i))
            n /= i, cnt++;
        flag &= !(cnt > 1);
    }
    return flag;
}

int main()
{
    vector<ll> sieve(MAX_N, 0);
    ll n = 0, N;
    sieve[1] = 1;
    for (ll i = 2; i < MAX_N; ++i)
        if (!sieve[i])
            for (ll j = i; j < MAX_N; j += i)
                sieve[j]++;
    
    vector<ll> M(MAX_N, 0);
    vector<ll> mu(MAX_N, 0);
    M[1] = mu[1] = 1;
    for (ll i = 2; i < MAX_N; ++i)
    {
        if (SquareFree(i))
            M[i] = (sieve[i] % 2? -1 : 1);
        mu[i] = mu[i - 1] + M[i];
    }
    
    while (cin >> N, N)
        cout << setw(8) << N << setw(8) << M[N] << setw(8) << mu[N] << '\n';
}
