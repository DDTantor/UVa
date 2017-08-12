#include <iostream>

using namespace std;

int main()
{
    int t, n, A[150][150];
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
                A[i + n][j] = A[i][j + n] = A[i + n][j + n] = A[i][j];
            }
        }

        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = 0; j < 2 * n; ++j)
            {
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        
        int best = -100 * 150 * 150;
        for (int i = 0; i < 2 * n; ++i)
        {
            for (int j = 0; j < 2 * n; ++j)
            {
                for (int x = i; x < 2 * n; ++x)
                {
                    for (int y = j; y < 2 * n; ++y)
                    {
                        if (x - i < n && y - j < n)
                        {
                            int sub = A[x][y];
                            if (i > 0) sub -= A[i - 1][y];
                            if (j > 0) sub -= A[x][j - 1];
                            if (i > 0 && j > 0) sub += A[i - 1][j - 1];
                            best = max(best, sub);
                        }
                    }
                }
            }
        }
        cout << best << '\n';
    }
}
