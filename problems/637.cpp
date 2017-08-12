#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    int n;
    string S[2] = {", front:", ", back :"};
    while (cin >> n, n)
    {
        cout << "Printing order for " << n << " pages:\n";
        int s = ceil(n / 4.0);
        int p = 0; // 0 front, 1 back
        for (int i = 0; i < 2 * s && i < n; ++i)
        {
            int num = s * 4 - i;
            int A[2] = {num, i + 1};
            cout << "Sheet " << i / 2 + 1 << S[p];
            for (int j = 0; j < 2; ++j)
            {
                if (A[(p + j) % 2] > n)
                    cout << " Blank";
                else
                    cout << " " << A[(p + j) % 2];
                cout << ((!j)? ',' : '\n');
            }
            p ^= 1;       
        }
        
    }
}
