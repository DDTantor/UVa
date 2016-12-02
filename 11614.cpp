#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << (long long)(-1 + sqrt(1 + 8 * n)) / 2 << '\n';
    }
}
