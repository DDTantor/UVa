#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        n -= (1 << (int)log2(n));
        cout << ((!n)? 1 : 2 * n) << '\n';
    }
}
    
