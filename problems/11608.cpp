#include <iostream>

using namespace std;

int A[12], a, n, cs = 1;

int main()
{
    while (cin >> n, n > -1)
    {
        cout << "Case " << cs++ << ":\n";
        for (int i = 0; i < 12; ++i)
            cin >> A[i];

        for (int i = 0; i < 12; ++i)
        {
            cin >> a;
            cout << "No problem" << (n < a? ". :(" : "! :D") << '\n';
            n = (n >= a? n - a: n) + A[i];
        }
    }
}
