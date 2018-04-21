#include <iostream>
#include <list>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    while (cin >> s)
    {
        list<char> L;
        auto it = L.begin();
        for (char c : s)
        {
            if (c == '[')
                it = L.begin();
            else if (c == ']')
                it = L.end();
            else
                L.insert(it, c);
        }

        for (char c : L)
            cout << c;

        cout << '\n';
    }
}
