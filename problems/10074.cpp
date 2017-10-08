#include <iostream>

using namespace std;

int main()
{
    int n, m, A[100][100];
    while (cin >> n >> m, m || n)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> A[i][j];
                if (i > 0)
                    A[i][j] += A[i - 1][j];

                if (j > 0)
                    A[i][j] += A[i][j - 1];

                if (i > 0 && j > 0)
                    A[i][j] -= A[i - 1][j - 1];
            }
        }
        int M = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int k = i; k < n; ++k)
                {
                    for (int l = j; l < m; ++l)
                    {
                        int s = A[k][l];
                        if (i > 0)
                            s -= A[i - 1][l];

                        if (j > 0)
                            s -= A[k][j - 1];

                        if (i > 0 && j > 0)
                            s += A[i - 1][j - 1];
                            
                        if (!s)
                            M = max(M, (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
        
        cout << M << '\n';
    }
}
