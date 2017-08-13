#include <iostream>

using namespace std;


int main()
{
    string s;
    int cs = 0, t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        cin >> s;
        s = s + "##";
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == '.')
                cnt++, s[i] = s[i + 1] = s[i + 2] = '#';

        cout << "Case " << ++cs << ": " << cnt << '\n';
    }
}
