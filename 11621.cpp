#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


typedef long long ll;
typedef vector<ll> vll;

ll M = 2147483648;

int main()
{
    vll A;
    ll sum1 = 1;
    while (sum1 <= M)
    {
        A.push_back(sum1);
        ll sum2 = 3 * sum1;
        while (sum2 <= M)
            A.push_back(sum2), sum2 *= 3;
        sum1 *= 2;
    }
    sort(A.begin(), A.end());
    ll n;
    while (cin >> n, n)
    {
        auto it = lower_bound(A.begin(), A.end(), n);
        cout << *it << '\n';
    }
}
