#include <iostream>

using namespace std;

int main()
{
    int t, c = 1, n, k, p;
    cin >> t;
    while (cin >> n >> k >> p, t--)
        cout << "Case " << c++ << ": " << (k - 1 + p) % n + 1 << '\n';
}
