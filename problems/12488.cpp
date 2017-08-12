#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, A[24], B[24];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        for (int i = 0; i < n; ++i)
            cin >> B[i];
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            int j = i;
            while (j < n && B[i] != A[j])
                j++;
            for (int k = j; k > i; --k)
                swap(A[k], A[k - 1]), cnt++;
        }
        cout << cnt << '\n';
    }
}
