#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

ll n, MAX_N = 20000000;
vector<ll> P;

int main()
{
    ll prev = 2;
    vector<ll> sieve(MAX_N, 0);
    for (ll i = 2; i < MAX_N; ++i)
    {
        if (sieve[i] == 0)
        {
            if (i - prev == 2)
                P.push_back(i);
            prev = i;
            for (int j = i; j < MAX_N; j += i)
                sieve[j]++;
        }
    }
    while (cin >> n)
    {
        cout << '(' << P[n - 1] - 2 << ", " << P[n - 1] << ")\n";
    }
}
