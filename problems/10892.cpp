#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll GCD(ll a, ll b)
{
    return (b == 0? a : GCD(b, a % b));
}

ll LCM(ll a, ll b)
{
    return a / GCD(a, b) * b;
}

ll Count(ll n)
{
    vector<ll> Div;
    for (int i = 1; i * i <= n; ++i)
    {
        if (!(n % i))
        {
            Div.push_back(i);
            if (i != n / i)
                Div.push_back(n / i);
        }
    }
    ll cnt = 0;
    for (int i = 0; i < Div.size(); ++i)
        for (int j = i; j < Div.size(); ++j)
            cnt+= (LCM(Div[i], Div[j]) == n);
        
    return cnt;
}

int main()
{
    ll n;
    while (cin >> n, n)
        cout << n << ' ' << Count(n) << '\n';
}
