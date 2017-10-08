#include <iostream>

using namespace std;

int main()
{
    int A[1000][1000], N, M;
    while (cin >> N >> M)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
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

        int sum = 0;
        for (int i = 0; i <= N - M; ++i)
        {
            for (int j = 0; j <= N - M; ++j)
            {
                int s = A[i + M - 1][j + M - 1];
                if (i > 0)
                    s -= A[i - 1][j + M - 1];

                if (j > 0)
                    s -= A[i + M - 1][j - 1];

                if (i > 0 && j > 0)
                    s += A[i - 1][j - 1];

                cout << s << '\n';
                sum += s;
            }
        }
        cout << sum << '\n';
        if (cin.ignore(2), !cin.eof())
            cout << '\n';
    }
}
