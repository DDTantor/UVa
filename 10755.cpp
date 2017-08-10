#include <iostream>
#include <climits>

using namespace std;

typedef long long ll;

ll A[20][20][20],  a, b, c, t;

int main()
{
    cin >> t;
    while (cin >> a >> b >> c, t--)
    {
        ll best = INT_MIN;
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                for (int k = 0; k < c; ++k)
                {
                    cin >> A[i][j][k];
                    if (i > 0) A[i][j][k] += A[i - 1][j][k];
                    if (j > 0) A[i][j][k] += A[i][j - 1][k];
                    if (k > 0) A[i][j][k] += A[i][j][k - 1];
                    if (i > 0 && j > 0) A[i][j][k] -= A[i - 1][j - 1][k];
                    if (i > 0 && k > 0) A[i][j][k] -= A[i - 1][j][k - 1];
                    if (j > 0 && k > 0) A[i][j][k] -= A[i][j - 1][k - 1];
                    if (i > 0 && j > 0 && k > 0) A[i][j][k] += A[i - 1][j - 1][k - 1];
                }
            }
        }
        for (int i = 0; i < a; ++i)
        {
            for (int j = 0; j < b; ++j)
            {
                for (int k = 0; k < c; ++k)
                {
                    for (int x = i; x < a; ++x)
                    {
                        for (int y = j; y < b; ++y)
                        {
                            for (int z = k; z < c; ++z)
                            {
                                ll sub = A[x][y][z];
                                if (i > 0) sub -= A[i - 1][y][z];
                                if (j > 0) sub -= A[x][j - 1][z];
                                if (k > 0) sub -= A[x][y][k - 1];
                                if (i > 0 && j > 0) sub += A[i - 1][j - 1][z];
                                if (i > 0 && k > 0) sub += A[i - 1][y][k - 1];
                                if (j > 0 && k > 0) sub += A[x][j - 1][k - 1];
                                if (i > 0 && j > 0 && k > 0) sub -= A[i - 1][j - 1][k - 1];
                                best = max(best, sub);
                            }
                        }
                    
                    }
                }
            }
        }
        cout << best << '\n';
        if (t)
            cout << '\n';
    }
}
