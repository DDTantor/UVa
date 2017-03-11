#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll s, d;
        cin >> s >> d;
        ll a = (s + d) / 2;
        ll b = (s - d) / 2;
        if (a + b == s && a - b == d && a >= 0 && b >= 0)
            cout << a << ' ' << b << '\n';
        else
            cout << "impossible\n";
    }
}
