#include <iostream>

using namespace std;

const int maxn = 31;

int L[31], U[31];

int main()
{
    L[1] = U[1] = 1;
    L[2] = U[2] = 2;
    for (int i = 3; i < 31; ++i)
        U[i] = L[i - 1] + L[i - 2], L[i] = L[i - 1] + U[i - 1];

    int n;
    while (cin >> n, n)
        cout << ((1 << n) - U[n] - L[n]) << '\n';
}
