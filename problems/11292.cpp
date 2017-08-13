#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m, D[20000], K[20000];
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < n; ++i)
            cin >> D[i];

        for (int i = 0; i < m; ++i)
            cin >> K[i];

        sort(D, D + n), sort(K, K + m);
        int cnt = 0, d = 0, k = 0;
        while (d < n && k < m)
        {
            while (D[d] > K[k] && k < m) k++;
            if (k == m) break;
            cnt += K[k];
            d++; k++;
        }
        if (d == n)
            cout << cnt << '\n';
        else
            cout << "Loowater is doomed!\n";
    }
}
