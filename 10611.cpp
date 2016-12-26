#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, A[50000], q, v;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cin >> q;
    while (q--)
    {
        cin >> v;
        int* h = upper_bound(A, A + n, v);
        int* l = lower_bound(A, A + n, v);
        if (l == A)
            cout << "X ";
        else
            cout << *(--l) << ' ';
        if (h == A + n)
            cout << "X\n";
        else
            cout << *h << '\n';
    }
}
