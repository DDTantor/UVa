#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long x;
    while (cin >> x)
    {
        long long n = log10(x) + 1;
        while (n++, (int)(log2(x) + log2(10) * n) == (int)(log2(x + 1) + log2(10) * n));
        cout << (int)(log2(x + 1) + log2(10) * n) << '\n';
    }
}
