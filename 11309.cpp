#include <iostream>
#include <stdio.h>

using namespace std;

bool IsPalindrome(string s)
{
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int a;
        cin >> s;
        s.erase(s.begin() + 2);
        do
        {
            a = stoi(s);
            a++;
            if (a % 100 > 59)
                a = (a / 100 + 1) * 100;
            if (a / 100 > 23)
                a = 0;
            s = to_string(a);
        }while (!IsPalindrome(s));
        while (s.length() < 4)
            s.insert(s.begin(), '0');
        
        s.insert(s.begin() + 2, ':');    
        cout << s << '\n';
    }
}
