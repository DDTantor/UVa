#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll A[4];
    int t;
    cin >> t;
    while (cin >> A[0] >> A[1] >> A[2] >> A[3], t--)
    {
        sort(A, A + 4);
        if (A[3] + A[1] + A[2] <= A[0] ||
            A[0] + A[2] + A[3] <= A[1] ||
            A[0] + A[1] + A[3] <= A[2] ||
            A[0] + A[1] + A[2] <= A[3])
            cout << "banana\n";
        else if (A[0] == A[1] && A[1] == A[2] && A[2] == A[3])
            cout << "square\n";
        else if (A[0] == A[1] && A[2] == A[3])
            cout << "rectangle\n";
        else
            cout << "quadrangle\n";
    }       
    
}
