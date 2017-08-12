#include <iostream>

using namespace std;

int main()
{
    int best, lds[2000], lis[2000], A[2000], n, t;
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i], lis[i] = lds[i] = 1;
                
        best = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (A[j] > A[i])
                    lis[i] = max(lis[i], lis[j] + 1);
                if (A[j] < A[i])
                    lds[i] = max(lds[i], lds[j] + 1);
            }
            best = max(best, lds[i] + lis[i] - 1);
        }
        cout << best << '\n';
    }
}
