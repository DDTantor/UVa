#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a != -1)
        cout << min(abs(a - b), 100 - abs(a - b)) << '\n';
}
