#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits> 

using namespace std;

typedef vector<int> vi;

int main()
{
    int t, A[8][8];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        vi C(n);
        iota(C.begin(), C.end(), 0);
        int m = INT_MAX;
        do
        {
            int sum = 0;
            for (int i = 0; i < n; ++i)
                sum += A[i][C[i]];

            m = min(sum, m);
        } while(next_permutation(C.begin(), C.end()));
        cout << m << '\n';
    }
}
