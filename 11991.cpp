#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main()
{
    ll m, n, k, v;
    while (cin >> n >> m)
    {
        map<ll, vll> V;
        for (int i = 0; i < n; ++i)
            cin >> k, V[k - 1].push_back(i + 1);
        
        for (int i = 0; i < m; ++i)
        {
            cin >> k >> v;
            if (k > V[v - 1].size())
                cout << "0\n";
            else
                cout << V[v - 1][k - 1] << '\n';
        }
    }
}
