#include <iostream>

using namespace std;

int main()
{
    int n, A[100][100];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> A[i][j];
                if (i > 0) A[i][j] += A[i - 1][j];
                if (j > 0) A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0) A[i][j] -= A[i - 1][j - 1];
            }
        }
        int best = -127 * 100 * 100;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int x = i; x < n; ++x)
                {
                    for (int y = j; y < n; ++y)
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
        cout << best << '\n';
    }
}
