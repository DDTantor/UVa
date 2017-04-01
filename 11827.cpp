#include <iostream>
#include <sstream>

using namespace std;

int GCD(int a, int b)
{
    return (b == 0? a : GCD(b, a % b));
}

int main()
{
    int A[100], t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n = 0, m = 0;
        string s;
        getline(cin, s);
        istringstream iss(s);
        while (iss >> A[n++]);
        n--;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                m = max(m, GCD(A[i], A[j]));
            
        cout << m << '\n';
    }
    
}
