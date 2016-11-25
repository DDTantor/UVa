#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        int m = 0, f = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 'M')
                m++;
            if (s[i] == 'F')
                f++;
        }
        if (m - f || (m == 1 && f == 1))
            cout << "NO ";
        cout << "LOOP\n";
    }
    
}
