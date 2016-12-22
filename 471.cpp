#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;
    
bool NoDupl(ll n)
{
    bool C[10] = {0};
    while (n)
    {
        if (C[n % 10])
            return false;
        C[n % 10] = true;
        n /= 10;
    }
    return true;
}

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (ll i = 1; i * n <= 9999999999 ; ++i)
            if (NoDupl(i * n) && NoDupl(i))
                cout << i * n << " / " << i << " = " << n << '\n';
        if (t)
            cout << '\n';
    }
    
}
