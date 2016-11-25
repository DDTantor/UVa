#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s[2];
    while (cin >> s[0], s[0] != "END")
    {
        s[1] = to_string(s[0].length());
        int i = 0;
        if (s[0] == "1")
        {
            cout << "1\n";
            continue;
        }
        while (s[0] != s[1])
        {
            s[1] = s[0];
            s[0] = to_string(s[0].length());
            ++i;
        }
        cout << i << '\n';
    }
}
