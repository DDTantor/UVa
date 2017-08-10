#include <iostream>
#include <algorithm>

using namespace std;

int n, A[100000];

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        int sum = 0, best = 0;
        for (int i = 0; i < n; ++i)
        {
            sum += A[i];
            best = max(sum, best);
            if (sum < 0)
                sum = 0;
        }
        if (sum == 0)
            cout << "Losing streak.\n";
        else
            cout << "The maximum winning streak is " << best << ".\n";
    }
}
