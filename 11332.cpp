#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        while (n >= 10)
            n = n / 10 + n % 10;
        
        cout << n << '\n';
    }
}
