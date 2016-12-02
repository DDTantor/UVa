#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int r, n, c = 1;
    while (cin >> r >> n, r || n)
    {
        cout << "Case " << c++ << ": ";
        int res = ceil((double)(r - n) / n);
        if (res > 26)
            cout << "impossible\n";
        else
            cout << res << '\n';
    }
}
