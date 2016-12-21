#include <iostream>

using namespace std;

int main()
{
    int k, n, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << (k ^ (k >> 1)) << '\n';
    }
}
