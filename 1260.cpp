#include <iostream>

using namespace std;

int main()
{
    int t, A[1000];
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        int sum = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (A[j] <= A[i])
                    sum++;
                    
        cout << sum << '\n';
    }
}
