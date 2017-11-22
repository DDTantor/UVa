#include <iostream>
#include <iomanip>

using namespace std;

#define eps 1e-6

typedef long long ll;

const ll maxn = 10001;
ll sol[maxn + 1];

bool IsPrime(ll n)
{
    for (int i = 2; i * i <= n; ++i)
        if (!(n % i))
            return false;

    return true;
}

int main()
{
    for (ll i = 0; i < maxn; ++i)
        sol[i + 1] = sol[i] + IsPrime(i * i + i + 41);

    ll a, b;
    while (cin >> a >> b)
    {
        double res = (sol[b + 1] - sol[a]) / double(b - a + 1);
        cout << fixed << setprecision(2) << 100.00 * res + eps << '\n';
    }
}
