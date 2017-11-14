#include <iostream>

using namespace std;

typedef long long ll;

int solve(ll n, ll l)
{
    int cnt = 1;
    while (n != 1 && n <= l)
    {
        ++cnt;
        if (n & 1)
            n = 3 * n + 1;
        else
            n /= 2;
    }

    return cnt - (n > l? 1 : 0);
}
int main()
{
    ios::sync_with_stdio(false);
    ll n, l, cs = 0;
    while (cin >> n >> l, n > 0 && l > 0)
        cout << "Case " << ++cs << ": A = " << n << ", limit = " << l << ", number of terms = " << solve(n, l) << '\n';
}
