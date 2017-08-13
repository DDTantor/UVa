#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    int n, d, r, N[100], M[100];
    while (cin >> n >> d >> r, n || d || r)
    {
        for (int i = 0; i < n; ++i)
            cin >> M[i];

        for (int i = 0; i < n; ++i)
            cin >> N[i];

        sort(M, M + n);
        sort(N, N + n, greater<int>());
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += (d >= M[i] + N[i]? 0 : r * (M[i] + N[i] - d));

        cout << sum << '\n';
    }
}
