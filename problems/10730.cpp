#include <iostream>

using namespace std;

int main()
{
    int n, A[10000];
    while (cin >> n, n)
    {
        cin.ignore();
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            bool B[10000] = {0};
            for (int j = 0; j <= i; ++j)
                B[A[j]] = true;
                
            for (int j = i + 1; j < n; ++j)
            {
                B[A[j]] = true;
                int a = 2 * A[j] - A[i];
                if (a >= 0 && a < n && j < n - 1 && !B[a])
                    flag = false;
            }
        }
        
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
