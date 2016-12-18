#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        if (b > a)
            cout << "0\n";
        else if (!(a % (2 * b)))
            cout << a / (2 * b) << '\n';
        else
        {
            int x1 = ceil(a / (2 * b)), x2  = x1 + 1; 
            int  f1 = (x1 * a - x1 * x1 * b), f2 = (x2 * a - x2 * x2 * b);
            if (f1 > f2)
                cout << x1 << '\n';
            else if (f1 < f2)
                cout << x2 << '\n';
            else
                cout << "0\n";
        }
    }
}
