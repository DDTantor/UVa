#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    unsigned int N, U, L;
    while (cin >> N >> L >> U)
    {
        unsigned int M = 0;
        unsigned int n = log2(U);
        for (int i = n; i >= 0; --i)
        {
            if (!(N & (1 << i)) && M + (1 << i) <= U)
                M |= (1 << i);
            else if (M + (1 << i) - 1 < L)
                M |= (1 << i);
        }
        cout << M << '\n';
    }
}
