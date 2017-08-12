#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

typedef long double ld;
typedef long long ll;

ll A, B, C;

//x ^ 3 - A * x ^ 2 + (A ^ 2 - C) * x / 2 - B = 0

ld BinSearch(ld lo, ld hi, int pad)
{
    for (int i = 0; i < 200; ++i)
    {
        ld m = (lo + hi) / 2;
        (((m * m * m - A * m * m + (A * A - C) * m / 2.0 - B < 0)
        == (pad > 0))? lo : hi) = m;
    }
    return lo;
}

int main()
{
    int t;
    cin >> t;
    while (cin >> A >> B >> C, t--)
    {
        if (A * A / 3.0 > C)
        {
            cout << "No solution.\n";
            continue;
        }
        ld D = (3.0 * C - A * A) * .5;
        ld a = (A - sqrtl(D)) / 3, b = (A + sqrtl(D)) / 3;
        
        ll x = (ll)round(BinSearch(-B, a, 1));
        ll y = (ll)round(BinSearch(a, b, -1));
        ll z = (ll)round(BinSearch(b, B, 1));
        
        if (x + y + z == A && x * y * z == B && x * x + y * y + z * z == C && x != y && y != z)
            cout << x << ' ' << y << ' ' << z << '\n';   
        else
            cout << "No solution.\n";
    }   
}
