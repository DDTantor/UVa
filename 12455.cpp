#include <iostream>

using namespace std;

int main()
{
    int t, n, a, A[20];
    cin >> t;
    while (cin >> a >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        bool flag = false;
        for (int i = 0; i < (1 << n); ++i)
        {
            int sum = 0;
            for (int j = 0; j < n; ++j)
                if (i & (1 << j))
                    sum += A[j];
            flag = (sum == a);
            if (flag)
                break;
            
        }
        if (flag)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
