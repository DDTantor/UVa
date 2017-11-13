#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n >> m)
        cout << m * n - 1 << '\n';
}
