#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        n = abs(n);
        int res = 0;
        for (int i = 1; !res; ++i)
            if (i * (i + 1) / 2 >= n && !((i * (i + 1) / 2 - n) % 2))
                res = i;

        cout << res << '\n';
        if (t)
            cout << '\n';
    }
       
}
