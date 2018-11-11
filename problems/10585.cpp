#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const ll maxn = 10005;
const ll maxx = 10000000;

ll cx, cy, n, X[maxn], Y[maxn], t;

string solve()
{
    if ((2 * cx) % n || (2 * cy) % n)
        return "no\n";

    cx = (2 * cx) / n, cy = (2 * cy) / n;
    
    set<ll> S;
    for (int i = 0; i < n; ++i)
        S.insert(X[i] * maxx + Y[i]);
    
    for (int i = 0; 2 * i < n; ++i)
    {
        ll xx = cx - X[i], yy = cy - Y[i];
        if (S.find(xx * maxx + yy) == S.end())
            return "no\n";
    }

    return "yes\n";
}
    
int main()
{
    cin >> t;
    
    while(cin >> n, t--)
    {
        cx = cy = 0;
        for (int i = 0; i < n; ++i)
            cin >> X[i] >> Y[i], cx += X[i], cy += Y[i];
        
        cout << solve();
    }
}
