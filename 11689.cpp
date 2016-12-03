#include <iostream>

using namespace std;

int main()
{
    int e, f, c, t;
    cin >> t;
    while (cin >> e >> f >> c, t--)
    {
        int r = (e + f - 1) / (c - 1);
        cout << ((r > 0)? r : 0) << '\n';
    }
}
