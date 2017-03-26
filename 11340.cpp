#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        int P[256], a, s = 0;
        memset(P, 0, sizeof(P));
        unsigned char c;
        for (int i = 0; i < n; ++i)
            cin >> c >> a, P[int(c)] = a;
            
        cin >> n, cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            while (c = cin.get(), c != '\n')
                s += P[c];
        }
        cout << fixed << setprecision(2) << s / 100.0 << "$\n";
    }
}
