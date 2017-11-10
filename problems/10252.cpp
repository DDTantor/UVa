#include <iostream>
#include <map>

using namespace std;

int main()
{
    string s1, s2;
    while (getline(cin, s1))
    {
        getline(cin, s2);
        int f1[26] = {}, f2[26] = {};
        for (char c : s1)
            ++f1[c - 'a'];

        for (char c : s2)
            ++f2[c - 'a'];

        string res = "";
        for (int i = 0; i < 26; ++i)
            res += string(min(f1[i], f2[i]), char('a' + i));

        cout << res << '\n';
    }
}
