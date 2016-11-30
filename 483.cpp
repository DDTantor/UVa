#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s))
    {
        s = s + " ";
        int j = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == ' ')
            {
                if (j)
                    cout << " ";
                string a = s.substr(j, i - j);
                reverse(a.begin(), a.end());
                cout << a;
                j = i + 1;
            }
        }
        
        cout << '\n';
    }
}
