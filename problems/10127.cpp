#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n)
    {
        int cnt = 0, res = 1 % n;
        while (res)
            ++cnt, res = (10 * res + 1) % n;

        cout << cnt + 1 << '\n';
    }
}
