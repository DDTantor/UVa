#include <iostream>
#include <string>

using namespace std;

bool IsPalindrome(string s)
{
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}

bool IsMirrored(string s)
{
    string a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string b = "A000300HIL0JM0O0002TUVWXY51SE0Z0080";
    int n = s.length();
    for (int i = 0; i < n; ++i)
    {
        int k = a.find(s[i]);
        if (b[k] != s[n - i - 1])
            return false;
    }
    return true;
}

int main()
{
    string s;
    while (cin >> s)
    {
        bool mir, pal;
        pal = IsPalindrome(s);
        mir = IsMirrored(s);
        cout << s << " -- is ";
        if (pal)
        {
            if (mir)
                cout << "a mirrored palindrome.\n";
            else
                cout << "a regular palindrome.\n";
        }
        else 
        {
            if (mir)
                cout << "a mirrored string.\n";
            else
                cout << "not a palindrome.\n";
        }
        cout << '\n';
    }
}
