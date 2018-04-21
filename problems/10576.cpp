#include <iostream>

using namespace std;

typedef long long ll;

int Solve(ll m, ll s, ll d)
{
    ll sum = 0, def = 0;
    for (int i = 0; i < 12; ++i)
    {
        ll a = (m & (1 << i)? s : d);
        sum += a, def += a;
        if (i > 3)
        {
            if (def >= 0)
                return -1;

            def -= (m & (1 << (i - 4))? s : d);
        }
    }

    return sum;
}

int main()
{
    ll s, d;
    while (cin >> s >> d)
    {
        int res = -1;
        for (int i = 0; i < (1 << 12); ++i)
            res = max(res, Solve(i, s, -d));

        if (res < 0)
            cout << "Deficit\n";
        else
            cout << res << '\n';
    }
}
