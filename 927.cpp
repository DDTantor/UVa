#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int t, C[21];
    cin >> t;
    while (t--)
    {
        int n, d, k;
        cin >> n;
        for (int i = n; i >= 0; --i)
            cin >> C[i];
    
        cin >> d >> k;
        ll sk = 0, sd = 0, an;
        for (int i = 1; sk < k; ++i)
        {
            an = 0;
            for (int j = 0; j <= n; ++j)
                an = an * i + C[j];
            sd += d;
            sk += sd;
        }
        cout << an << '\n';
    }
}
