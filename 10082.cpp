#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    string s[2] = {"1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./", 
                   "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,."};
                   
    string a;
    while (getline(cin, a))
    {
        for (int i = 0; i < a.size(); ++i)
        {
            if (a[i] != ' ')
                cout << s[1][s[0].find(a[i])];
            else
                cout << ' ';
        }
        cout << '\n';
    }
}
