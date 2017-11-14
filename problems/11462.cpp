#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

int main()
{
    int n;
    while (cin >> n, n)
    {
        vi A(n, 0);
        int m = A[0], M = A[0];
        for (int i = 0; i < n; ++i)
            cin >> A[i], m = min(m, A[i]), M = max(M, A[i]);

        vi f(M - m + 1);
        for (int i = 0; i < n; ++i)
            ++f[A[i] - m];

        bool flag = false;
        for (int i = 0; i < M - m + 1; ++i)
            while (f[i])
                cout << (flag? " " : "") << i + m, --f[i], flag |= true;

        cout << '\n';
    }
        
        
}
