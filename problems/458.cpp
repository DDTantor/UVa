#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        for (int i = 0; i < s.size(); ++i)
            cout << char(s[i] - 7);
        cout << '\n';
    }
}
