#include <iostream>

using namespace std;

int f(int n)
{
    if (n > 100)
        return n - 10;
    return f(f(n + 11));
}

int main()
{
    int n;
    while (cin >> n, n)
        cout << "f91(" << n << ") = " << f(n) << '\n';
}
