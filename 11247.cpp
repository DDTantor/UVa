#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll m, x, res;
    while (cin >> m >> x, m || x)
    {
        if (x == 100)
            goto stop;
        res = (m - 1) * 100 / (100 - x);
        if (!((m - 1) * 100 % (100 - x)))
            res--;
            
        if (res < m || m == 1)
            stop : cout << "Not found\n";
        else
            cout << res << '\n';
    }
}
