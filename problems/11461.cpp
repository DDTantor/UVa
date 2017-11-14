#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int a, b;
    while (cin >> a >> b, a || b)
        cout << int(sqrt(b)) - int(sqrt(a - 1)) << '\n';
}
