#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int s[10000] = {0}, L, H, R;
    int mn = 10000, mx = 0;
    while (cin >> L >> H >> R)
    {
        mx = max(mx, R);
        mn = min(mn, L);
        for (int i = L; i < R; ++i)
            s[i] = max(s[i], H);
    }
    for (int i = mn; i <= mx; ++i)
    {
        if (s[i] != s[i - 1])
        {
            if (i > mn)
                cout << ' ';
            cout << i << ' ' << s[i];
        }
    }
    cout << '\n';
}
