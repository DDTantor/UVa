#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

typedef long long ll;
const ll MAX_N = 10000000;

ll GCD(ll A, ll B)
{
    return (B == 0? A : GCD(B, A % B));
}

ll LCM(ll A, ll B)
{
    return A / GCD(A, B) * B;
}

ll Solve(ll A, ll C)
{
    if (C % A)
        return 0;
        
    ll B = C / A;
    for (ll i = B; B <= MAX_N; i += B)
        if (LCM(A, i) == C)
            return i;
}

int main()
{
    ll A, C;
    int t;
    cin >> t;
    while (cin >> A >> C, t--)
    {
        ll res = Solve(A, C);
        if (res)
            cout << res << '\n';
        else
            cout << "NO SOLUTION\n";
        
    }
}
