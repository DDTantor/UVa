#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, fl, A[1422];
    while (cin >> n, n)
    {
        fl = 1, prev = 0;
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        sort(A, A + n);
        for (int i = 0; i < n - 1; ++i)
            fl &= (A[i + 1] - A[i] <= 200);
        
        fl &= (2 * (1422 - A[n - 1]) <= 200);
        cout << (fl? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}
