#include <iostream>
#include <cstring>

using namespace std;

string s;
int A[10][10], B[10][10], res;

int main()
{
    ios::sync_with_stdio(false);
    while (getline(cin, s), s != "end")
    {
        cout << s << ' ';
        memset(A, 0, sizeof A);
        for (int i = 0; i < 10; ++i)
        {
            getline(cin, s);
            for (int j = 0; j < 10; ++j)
                A[i][j] = (s[j] == 'O');
        }
                
        res = int(1e9);
        for (int b = 0; b < (1 << 10); ++b)
        {
            memcpy(B, A, sizeof A);
            for (int i = 0; i < 10; ++i)
            {
                if (b & (1 << i))
                {
                    for (int k = -1; k <= 1; ++k)
                        if (i + k >= 0 && i + k < 10)
                            B[0][i + k] = !B[0][i + k];

                    B[1][i] = !B[1][i];
                }
            }

            int r = __builtin_popcount(b);
            for (int i = 1; i < 10; ++i)
            {
                for (int j = 0; j < 10; ++j)
                {
                    if (B[i - 1][j] == 1)
                    {
                        ++r;
                        for (int k = -1; k <= 1; ++k)
                            if (j + k >= 0 && j + k < 10)
                                B[i][j + k] = !B[i][j + k];

                        if (i < 9)
                            B[i + 1][j] = !B[i + 1][j];
                    }
                }
            }
            int tmp = 0;
            for (int i = 0; i < 10; ++i)
                tmp += B[9][i];
            
            if (!tmp)
                res = min(r, res);
        }

        cout << (res == int(1e9)? -1 : res) << '\n';
    }
}
