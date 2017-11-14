#include <iostream>

using namespace std;

int A[100][100];

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

        int R[2][100] = {{0}, {0}};
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                R[0][i] += A[i][j], R[1][i] += A[j][i];
        
        int cntr = 0, cntc = 0, r = 0, c = 0;
        for (int i = 0; i < n; ++i)
        {
            if (R[0][i] & 1)
                cntr++, r = i + 1;

            if (R[1][i] & 1)
                cntc++, c = i + 1;
        }

        if (cntr == 0 && cntc == 0)
            cout << "OK\n";
        else if (cntc == 1 && cntr == 1)
            cout << "Change bit (" << r << ',' << c << ")\n";
        else
            cout << "Corrupt\n";      
    }
}
