#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int t, n, cs = 0, dc, ic;
vi A, B;
vi lds, lis;

int main()
{
    int t, n;
    cin >> t;
    while(cin >> n, t--)
    {
        A.resize(n); B.resize(n);
        lis.assign(n, 0); lds.assign(n, 0);
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        for (int i = 0; i < n; ++i)
            cin >> B[i], lis[i] = lds[i] = B[i];

        ic = dc = B[0];
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (A[i] > A[j])
                    lis[i] = max(lis[i], lis[j] + B[i]);
                if (A[i] < A[j])
                    lds[i] = max(lds[i], lds[j] + B[i]);
            }
            ic = max(ic, lis[i]);
            dc = max(dc, lds[i]);
        }
        cout << "Case " << ++cs << ". ";
        if (dc > ic)
            cout << "Decreasing (" << dc << "). Increasing (" << ic << ").\n";
        else
            cout << "Increasing (" << ic << "). Decreasing (" << dc << ").\n";
    }
}
