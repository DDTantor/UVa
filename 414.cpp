#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int A[13], n;
    string s;
    while(cin >> n, n)
    {
        cin.ignore();
        int min = 25, res = 0;
        for (int i = 0; i < n; ++i)
        {   
            getline(cin, s);
            A[i] = 25 - count(s.begin(), s.end(), 'X');
            if (A[i] < min)
                min = A[i];
        }
        for (int i = 0; i < n; ++i)
            res += A[i] - min;
        
        cout << res << '\n';
    }
    
}
