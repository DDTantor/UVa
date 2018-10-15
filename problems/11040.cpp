#include <iostream>

using namespace std;

int A[9][9], n;

int main()
{
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < i + 1; ++j)
                cin >> A[2 * i][2 * j];

        for (int k = 0; k < 4; ++k)
            A[8][2 * k + 1] = (A[6][2 * k] - A[8][2 * k] - A[8][2 * k + 2]) / 2;

        for (int i = 7; i >= 0; --i)
            for (int j = 0; j < i + 1; ++j)
                A[i][j] = A[i + 1][j] + A[i + 1][j + 1];

        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < i + 1; ++j)
            {
                if (j)
                    cout << ' ';

                cout << A[i][j];
            }

            cout << '\n';
        }
    }
}
