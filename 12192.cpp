#include <iostream>
#include <algorithm>

using namespace std;

int A[500][500];
int n, m, q, L, U;

int main()
{
    while (cin >> n >> m, n && m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];
        cin >> q;
        for (int j = 0; j < q; ++j)
        {
            cin  >> L >> U;
            int cmax = 0;
            for (int i = 0; i < n; ++i)
            {
                int* low = lower_bound(A[i], A[i] + m, L);
                int start = low - A[i];
                int k = cmax;
                while (start + k < m && i + k < n && A[i + k][start + k] <= U)
                    cmax = (cmax < k + 1? k + 1 : cmax), k++; 
            }
            cout << cmax << '\n';
        }
        cout << "-\n";
    } 
}
