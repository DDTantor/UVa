#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, q, A[10000], a, c = 1;
    while (cin >> n >> q, n || q)
    {
        cout << "CASE# " << c++ << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        sort(A, A + n);
        while (q--)
        {
            cin >> a;
            int* f = lower_bound (A, A + n, a);
            if (a == *f)
                cout << a << " found at "<< f - A + 1 << '\n';
            else
                cout << a << " not found\n";
        }
    }
    
}
