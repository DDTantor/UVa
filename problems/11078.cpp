#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, max = -150000, res = -150000;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int s;
            cin >> s;
            if (max - s > res)
                 res = max - s;
            if (s > max)
                max  = s;
        }
        cout << res << '\n';
    }
    
}
