#include <iostream>

using namespace std;

int A[20000];

int main()
{
    int t, cs = 1;
    cin >> t;
    while (t--)
    {
        int n, s = 0, e = 0, sum = 0, ans = 0, s2 = 0;
        cin >> n;
        for (int i = 0; i < n - 1; ++i)
            cin >> A[i];
        
        for (int i = 0; i < n - 1; ++i)
        {
            sum += A[i];
            if (sum < 0)
                sum = 0, s2 = i + 1;
            else if (ans < sum || ans == sum && i + 1 - s2 > e - s)
                ans = sum, e = i + 1, s = s2;
        }
        if (e > 0)
            cout << "The nicest part of route " << cs++ << " is between stops " << s + 1 << " and " << e + 1 << '\n';
        else
            cout << "Route " << cs++ << " has no nice parts\n"; 
    }
}
