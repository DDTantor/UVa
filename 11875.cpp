#include <iostream>

using namespace std;

int main()
{
    int t, n, k, c = 1;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << "Case " << c++ << ": ";
        for (int i = 0; i < n; ++i)
        {
            cin >> k;
            if (i == n / 2) cout << k << '\n';
        }
    }
}
