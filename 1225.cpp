#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        int A[10] = {0};
        for (int i = 1; i <= n; ++i)
        {
            int j = i;
            while (j)
            {
                A[j % 10]++;
                j /= 10;
            }
        }
        for (int i = 0; i < 10; ++i)
            cout << A[i] << ((i < 9)? ' ' : '\n');
    }
    
}
