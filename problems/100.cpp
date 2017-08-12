#include <iostream>
#include <algorithm>

using namespace std;

int Collatz(int n)
{
    int t = 1;
    while (n != 1)
    {
        if (n % 2)
            n = 3 * n + 1;
        else
            n /= 2;
        t++;
    }
    return t;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int m = 1;
        for (int i = min(a, b); i <= max(b, a); ++i)
            m = max(m, Collatz(i));
        
        cout << a << ' ' << b << ' ' << m << '\n';
    }
}
