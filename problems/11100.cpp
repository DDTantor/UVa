#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int main()
{
    int n, B[10000];
    while (cin >> n, n)
    {
        memset(B, 0, sizeof(B));
        for (int i = 0; i < n; ++i)
            cin >> B[i];

        sort(B, B + n);
        int cnt = 0, c = 1;
        for (int i = 0; i < n; ++i)
        {
            if (B[i] == B[i + 1])
                c++;
            else
                cnt = max(cnt, c), c = 1;
        }
        cout << cnt << '\n';
        for (int i = 0; i < cnt; ++i)
        {
            for (int j = i; j < n; j += cnt)
            {
                if (j != i)
                    cout << ' ';
                cout << B[j];
            }
            cout << '\n';
        }
        cout << '\n';
    }
}
