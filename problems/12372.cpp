#include <iostream>

using namespace std;

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        int A[3], max = 0;
        for (int i = 0; i < 3; ++i)
        {
            cin >> A[i];
            if (A[i] > max)
                max = A[i];
        }
        cout << "Case " << c++ << ": " << ((max > 20)? "bad" : "good") << '\n';
    }
    
}
