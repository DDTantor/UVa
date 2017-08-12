#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    int a, t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        vector<int> A(n + 1);
        map<int, int> M;
        int m = 0, t = 0;
        for (int i = 1; i <= n; ++i)
            cin >> A[i];
            
        for (int i = 1; i <= n; ++i)
        {
            if (!M[A[i]])
                t++, M[A[i]] = i;
            else
                i = M[A[i]], M.clear(), t = 0;
            m = max(t, m);
        }
        cout << m << '\n';
    }
}
