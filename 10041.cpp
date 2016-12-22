#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t, n, A[500];
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        int min = 30000 * 500;
        for (int i = 0; i < n; ++i)
        {
            int dist = 0;
            for (int j = 0; j < n; ++j)
                dist += abs(A[i] - A[j]);
            if (dist < min)
                min = dist;
        }
        cout << min << '\n';
    }
}
