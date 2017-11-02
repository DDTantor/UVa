#include <iostream>

using namespace std;

typedef long long ll;

ll Mod(ll a, ll k, ll n)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % n;

        a = (a * a) % n;
        k /= 2;
    }

    return res;
}

int main()
{
    int t;
    ll a, k, n;
    cin >> t;
    while (cin >> a >> k >> n, t--)
        cout << Mod(a, k, n) << '\n';
}
