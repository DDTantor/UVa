#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1000000;
int sum[maxn];

int main()
{
    int t, a, b, n;
    cin >> t;
    while (cin >> n, t--)
    {
        memset(sum, 0, sizeof sum);
        for (int i = 0; i < n; ++i)
            cin >> a >> b, sum[n - i - 1] = a + b;
        
        for (int i = 0; i < n; ++i)
            if (sum[i] > 9)
                sum[i] = sum[i] % 10, sum[i + 1]++;
        

        for (int i = (sum[n]? n : n - 1); i >= 0; --i)
            cout << sum[i];

        cout << '\n';
        if (t)
            cout << '\n';
    }
}
