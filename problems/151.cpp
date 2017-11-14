#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

typedef vector<int> vi;

int solve(int n)
{
    for (int i = 1;; ++i)
    {
        vi A(n, 0);
        iota(A.begin(), A.end(), 1);
        int k = 0;
        while (A[k] != 13)
        {
            A.erase(A.begin() + k);
            k += i - 1;
            if (k >= A.size())
                k = k % A.size();
        }

        if (A.size() == 1)
            return i;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n, n)
        cout << solve(n) << '\n';
}
