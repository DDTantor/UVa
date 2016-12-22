#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

typedef long long ll;

int main()
{
    ll n, q, A[1000], c = 1;
    while (cin >> n, n)
    {
        cout << "Case " << c++ << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        cin >> q;
        for (int i = 0; i < q; ++i)
        {
            ll s;
            ll min = A[0] + A[1];
            cin >> s;
            for (int j = 0; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    if (abs(A[j] + A[k] - s) < abs(min - s))
                        min = A[j] + A[k];
            cout << "Closest sum to " << s << " is " << min  << ".\n";
        }
    }
}
