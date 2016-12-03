#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b, d, c;
    double n;
    while (cin >> a >> b >> n)
    {
        d = 0;
        while (++d)
        {
            c = (long double)a / b * d;
            while (a * d >= c * b)
                c++;
            if ((long double)c / d - (long double)a / b <= n)
            {
                cout << c << ' ' << d << '\n';
                break;
            }
        }
    }
}
