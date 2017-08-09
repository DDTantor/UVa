#include <iostream>
#include <iomanip>

using namespace std;

typedef long long ll;

int main()
{
    for (int  a = 1; 4 * a <= 2000; ++a)
    {
        for (int b = a; 3 * b + a <= 2000; ++b)
        {
            for (int c = b; 2 * c + a + b <= 2000; ++c)
            {
                ll p = a * b * c, s = a + b + c;
                if (p - 1000000 > 0 && !(1000000 * s % (p - 1000000)) )
                {
                    int d = (s * 1000000) / (p - 1000000);
                    if (s + d <= 2000 && (a + b + c + d) / 100 == (a * b * c * d) / 100000000 && c <= d)
                            cout << setprecision(2) << fixed << (float)a/100 << ' ' << (float)b/100 << ' ' << (float)c/100 << ' ' << (float)d/100 << '\n';
                }
            }
        }
    }
}
