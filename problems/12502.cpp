#include <iostream>

using namespace std;

int main()
{
    int t, a, b, m;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> m;
        int r;
        if (2 * a <= b)
            r = 0;
        else if (a < 2 * b)
            r = (2 * m * a - m * b) / (a + b);
        else
            r = m;
        cout << r << '\n';
    }
}
