#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        cout << (int)(ceil((m - 2) / 3.0) * ceil((n - 2) / 3.0)) << '\n';
    }
}
