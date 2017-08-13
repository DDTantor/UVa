#include <iostream>

using namespace std;

int main()
{
    long long C[1000];
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> C[i];

        int sum = 1, cnt = (n > 1? 2 : 1);
        for (int i = 1; i < n - 1; ++i)
            if (sum + C[i] < C[i + 1])
                sum += C[i], cnt++;

        cout << cnt << '\n';
    }
}
