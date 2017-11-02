#include <iostream>

using namespace std;

typedef long long ll;

ll Mod(ll a, ll k, ll p)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = (res * a) % p;

        a = (a * a) % p;
        k /= 2;
    }

    return res;
}

bool IsPrime(ll p)
{
    for (int i = 2; i * i <= p; ++i)
        if (!(p % i))
            return false;

    return true;
}

int main()
{
    ll p, a;
    while (cin >> p >> a, p && a)
        cout << (Mod(a, p, p) == a && !IsPrime(p)? "yes\n" : "no\n");
}
