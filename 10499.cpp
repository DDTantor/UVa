#include <iostream>

using namespace std;

int main()
{
    long long n;
    while (cin >> n, n > 0)
        cout << ((n > 1)? ((n + 4) * 100 / 4) - 100 : 0) << "%\n";
}
