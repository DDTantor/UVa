#include <iostream>
#include <cstring>

using namespace std;

int t, n;

int main()
{
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        
        string S[26];
        int A[25][25];
        memset(A, 0, sizeof(A));
        n = 0;
        while (getline(cin, S[n]), !S[n++].empty());

        n--;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                A[i][j] = (S[i][j] == '1');
                if (i > 0)
                    A[i][j] += A[i - 1][j];

                if (j > 0)
                    A[i][j] += A[i][j - 1];

                if (i > 0 && j > 0)
                    A[i][j] -= A[i - 1][j - 1];
            }
        }

        int best = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = i; k < n; ++k)
                {
                    for (int l = j; l < n; ++l)
                    {
                        int sum = A[k][l];
                        if (i > 0)
                            sum -= A[i - 1][l];

                        if (j > 0)
                            sum -= A[k][j - 1];

                        if (i > 0 && j > 0)
                            sum += A[i - 1][j - 1];

                        if (sum == (k + 1 - i) * (l + 1 - j))
                            best = max(sum, best);
                    }
                }
            }
        }

        cout << best << '\n';
        if (t)
            cout << '\n';
        
    }
}
