#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        cout << "Case " << c++ << ": ";
        ll a, b, c;
        cin >> a >> b >> c;
        if (a >= b + c || c >= a + b || b >= a + c || a <= 0 || b <= 0 || c <= 0)
            cout << "Invalid\n";
        else if (a == b && b == c)
            cout << "Equilateral\n";
        else if (a == b || b == c || c == a)
            cout << "Isosceles\n";
        else
            cout << "Scalene\n";
    }
}
