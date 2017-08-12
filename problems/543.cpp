#include <iostream>

using namespace std;

typedef long long ll;

ll n;

bool isPrime(ll p)
{
    for (int i = 2; i * i <= p; ++i)
        if (!(p % i))
            return false;
    
    return true;
}

int Solve()
{
    for (ll i = 3; 2 * i <= n; ++i)
    {
        if (isPrime(i) && isPrime(n - i))
            return i;
    }
    return 0;
}

int main()
{
    while (cin >> n, n)
    {
        int res = Solve();
        cout << n << " = " << res << " + " << n - res << endl; 
    }
}
