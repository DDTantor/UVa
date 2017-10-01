#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, s, f, x, y;
    while (cin >> n, n)
    {
        s = sqrt(n);
        n -= s * s;
        f = s % 2;
        (f? x : y) = 1;
        (f? y : x) = s;
        
        if (n > 0)
            n--, (f? y : x)++;

        if (n > 0)
            (f? x : y) += min(s, n), n -= min(s, n);

        if (n > 0)
            (f? y : x) -= n;

        cout << x << ' ' << y << endl;
        
    }
}
