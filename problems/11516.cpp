#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

#define eps 1e-2

int A[100000], m, n, t;

bool Place(double mid)
{
    int k = m - 1;
    double curr = A[0] + mid;
    for (int i = 1; i < n; ++i)
        if (fabs(A[i] - curr) > mid - eps)
            curr = A[i] + mid, --k;
    
    return k >= 0;
}

int main()
{
    cin >> t;
    while (cin >> m >> n, t--)
    {
        double lo = 0.0, hi = 1e9;
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        sort(A, A + n);
        while (fabs(lo - hi) > eps)
        {
            double mid = (lo + hi) / 2.0;
            if (Place(mid))
                hi = mid;
            else
                lo = mid;
        }

        cout << fixed << setprecision(1) << hi << '\n';
    }
}
