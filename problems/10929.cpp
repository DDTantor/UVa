#include <iostream>

using namespace std;

int main()
{
    string s;
    while (cin >> s, s != "0")
    {
        int sum = 0, i = 1;
        for (char c : s)
            sum += i * (c - '0'), i *= -1;

        cout << s << " is " << (!(sum % 11)? "" : "not ") << "a multiple of 11.\n";
    }
}
