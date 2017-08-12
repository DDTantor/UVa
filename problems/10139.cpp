#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;

int GetPower(ll n, ll p)
{
    ll res = 0;
    for (ll power = p; power <= n; power *= p)
        res += n / power;
    
    return res;
}

int main()
{
    ll m, n;
    while (cin >> m >> n) //n dijeli m
    {
        vllll P;
        cout << n << ' ';
        for (int i = 2; i * i <= n; ++i)
        {
            int cnt = 0;
            while (!(n % i))
                n /= i, cnt++;
            
            if (cnt)
                P.emplace_back(i, cnt);
        }
        if (n > 1)
            P.emplace_back(n, 1);
        
        bool flag = true;
        for (auto p : P)
            flag &= (p.second <= GetPower(m, p.first));
        
        if (flag)
            cout << "divides ";
        else
            cout << "does not divide ";
        cout << m << "!\n";
    }
}
