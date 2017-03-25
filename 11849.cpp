#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    int m, n;
    while (cin >> m >> n, m || n)
    {
        set<ll> M;
        ll k, cnt = 0;
        for (int i = 0; i < m; ++i)
            cin >> k, M.insert(k);
            
        for (int i = 0; i < n; ++i)
            cin >> k, cnt += M.count(k);
            
        cout << cnt << '\n';
    }
}
