#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int f, a, b, sum = 0;
        cin >> f;
        for (int i = 0; i < f; ++i)
        {
            cin >> a >> b >> b;
            sum += a * b;
        }
        cout << sum << '\n';
    }
}
