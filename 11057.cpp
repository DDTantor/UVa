#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, p, A[10000];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        sort(A, A + n);
        int best = 0;
        cin >> p;
        for (int i = 0; 2 * A[i] <= p; ++i)
        {
            int tmp = A[i];
            bool flag = (binary_search(A, A + i, p - tmp) || binary_search(A + i + 1, A + n, p - tmp));
            if (flag && (p - 2 * best) > (p - 2 * tmp))
                best = tmp;
            A[i] = tmp;
        }
        cout << "Peter should buy books whose prices are " << best << " and " << p - best << ".\n\n";
    }
}
