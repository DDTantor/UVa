#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, N[100];
    cin >> t;
    while (t--)
    {
        int n, j, sum = 0;
        string s;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            if (s == "LEFT")
                N[i] = -1;
            if (s == "RIGHT")
                N[i] = 1;
            if (s == "SAME")
            {
                cin >> s >> j;
                N[i] = N[j - 1];
            }
            sum += N[i];
        }
        cout << sum << '\n';
    }
}
