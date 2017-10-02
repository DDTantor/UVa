#include <iostream>
#include <cstring>

using namespace std;

int n, m, cnt, A[100][100], sum;
char c;

int main()
{
    while (cin >> n >> m, n)
    {
        memset(A, 0, sizeof(A));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                cin >> c;
                A[i][j] = c - '0';
                if (i > 0)
                    A[i][j] += A[i - 1][j];
                if (j > 0)
                    A[i][j] += A[i][j - 1];
                if (i > 0 && j > 0)
                    A[i][j] -= A[i - 1][j - 1];
            }
        }
        
        cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                for (int k = i; k < n; ++k)
                {
                    for (int l = j; l < m; ++l)
                    {
                        sum = A[k][l];
                        if (i > 0)
                            sum -= A[i - 1][l];
                        if (j > 0)
                            sum -= A[k][j - 1];
                        if (i > 0 && j > 0)
                            sum += A[i - 1][j - 1];
                        cnt += (sum == (k - i + 1) * (l - j + 1));
                    }
                }
            }
        }
        
        cout << cnt << '\n';
    }
}
