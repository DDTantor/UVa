#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c = 1;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;  
        if (!(a % 2))
            a++;
        if (!(b % 2))
            b--;
        cout << "Case " << c++ << ": " << ((b - a) / 2 + 1) * (a + b) / 2 << '\n';
    }
}
