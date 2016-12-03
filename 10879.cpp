#include <iostream>

using namespace std;

int main()
{
    int t, n, c = 1;
    cin >> t;
    while (cin >> n, t--)
    {
        int f = 0, A[2][2];
        for (int i = 2; f < 2; ++i)
            if (!(n % i))
                A[0][f] = i, A[1][f] = n / i, ++f;
                
        cout << "Case #" << c++ << ": " << n << " = " << A[0][0] << " * " << A[1][0] << " = " << A[0][1] << " * " << A[1][1] << '\n';
    }
}
