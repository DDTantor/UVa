#include <iostream>

using namespace std;


int main()
{
    int b, s, B[10000], S[10000], cs = 1;
    while (cin >> b >> s, b || s)
    {
        int m = 60;
        for (int i = 0; i < b; ++i)
            cin >> B[i], m = min(m, B[i]);

        for (int i = 0; i < s; ++i)
            cin >> S[i];

        cout << "Case " << cs++ << ": ";
        if (b <= s)
            cout << "0\n";
        else
            cout << b - s << ' ' << m << '\n';
    }
}
