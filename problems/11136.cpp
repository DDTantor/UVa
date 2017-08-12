#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    while (cin >> n, n)
    {
        ll k, sum = 0, p;
        multiset<ll> P;
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            for (int j = 0; j < k; ++j)
            {
                cin >> p;
                P.insert(p);
            }
            sum += *(--P.end()) - *P.begin();
            P.erase(--P.end()), P.erase(P.begin());
        }
        cout << sum << '\n';
    }
}
