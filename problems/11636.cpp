#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    int n, cs = 0;
    while (cin >> n, n > 0)
        cout << "Case " << ++cs << ": " << ceil(log2(n)) << '\n';
}
