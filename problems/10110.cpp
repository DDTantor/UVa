#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    ll n;
    while (cin >> n, n)
        cout << (ll(sqrt(n)) * ll(sqrt(n)) == n? "yes\n" : "no\n");
}
