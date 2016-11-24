#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string s;
    bool b = false;
    string a[2] = {"``", "''"};
    while(getline(cin, s))
    {
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == '"')
            {
                cout << a[b];
                b = !b;
            }
            else 
                cout << s[i];
        }
        cout << '\n';
        s.clear();
    }
}
