#include <iostream>

using namespace std;

int main()
{
    int t, n, k, p, A[100];
    char c;
    cin >> t;
    while (t--)
    {
        bool C[100] = {0};
        cin >> n >> k;
        for (int i = 0; i < k; ++i)
        {
            cin >> p;
            for (int j = 0; j < p * 2; ++j)
                cin >> A[j];
            cin >> c;
            if (c == '=')
                for (int j = 0; j < p * 2; ++j)
                    C[A[j] - 1] = true;
            else
            {
                for (int j = 0; j < n; ++j)
                {
                    bool flag = true;
                    for (int l = 0; l < p * 2; ++l)
                        if (j == A[l] - 1)
                            flag = false;
                    C[j] |= flag;
                }
            }
        }
        int b, cnt = 0;
        for (int i = 0; i < n; ++i)
            if (!C[i])
                b = i, cnt++;
        if (cnt == 1)
            cout << b + 1 << '\n';
        else
            cout << '0' << endl;
        if (t)
            cout << '\n';
    }
    
}
