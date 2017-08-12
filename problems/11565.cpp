#include <iostream>

using namespace std;

int A, B, C;

void solve()
{
    for (int x = -100; x <= 100; ++x)
    {
        for (int y = -100; y <= 100; ++y)
        {
            for (int z = -100; z <= 100; z++)
            {
                if (x != y && z != y && x != z && x + y + z == A && x * y * z == B && x * x + y * y + z * z == C)
                {
                    cout << x << ' ' << y << ' ' << z << '\n';
                    return;
                }
            }
        }
    }
    cout << "No solution.\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> A >> B >> C;
        solve();
    }
}
