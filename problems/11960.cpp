#include <iostream>

using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 1;
ll IsPrime[maxn], Prime[maxn], p, n, t, D[maxn], A[maxn]; 

void SimpleSieve()
{
    IsPrime[0] = IsPrime[1] = 1;
    for (ll i = 2; i < maxn; ++i)
    {
        if (!IsPrime[i])
        {
            for (ll j = i * i; j < maxn; j += i)
                IsPrime[j] = 1;
            
            Prime[p++] = i;
        }
    }
}

ll NumDiv(int n)
{
    ll id = 0, pr = Prime[id], res = 1;
    while (pr * pr <= n)
    {
        ll pw = 0;
        while (!(n % pr)) n /= pr, ++pw;

        res *= (pw + 1);
        pr = Prime[++id];
    }
    if (n != 1) res *= 2;

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    SimpleSieve();
    cin >> t;

    for (int i = 2; i < maxn; ++i)
        D[i] = NumDiv(i);

    for (int i = 1; i < maxn; ++i)
        A[i] = (D[i] < D[A[i - 1]]? A[i - 1] : i);

    while (cin >> n, t--)
        cout << A[n] << '\n';
}
