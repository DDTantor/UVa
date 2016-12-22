#include <iostream>

using namespace std;

int main()
{
    int t, d, b;
    cin >> t;
    while (cin >> d >> b, t--)
    {
        b--;
        int sol = 0;
        for (int i = 1; i < d; ++i)
        {
            sol <<= 1;
            sol |= (b & 1);
            b >>= 1;
        }
        cout << (sol + (1 << (d - 1))) << '\n';
    }
}
