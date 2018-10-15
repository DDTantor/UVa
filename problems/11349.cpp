#include <iostream>

using namespace std;

int n, t, cs = 1;
long int A[100][100];
char c;

bool check()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != A[n - i - 1][n - j - 1] || A[i][j] < 0)
                return false;

    return true;
}

int main()
{
    cin >> t;
    while (cin >> c >> c >> n, t--)
    {
        cout << "Test #" << cs++ << ": ";
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        cout << (check()? "Symmetric.\n" : "Non-symmetric.\n");
    }
}
