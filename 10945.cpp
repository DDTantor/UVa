#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool IsPalindrome(string s)
{
    int n = s.length();
    for (int i = 0; i < n; ++i)
        if (s[i] != s[n - i - 1])
            return false;  
                
    return true;
}
int main()
{
    string s;
    while (getline(cin, s), s != "DONE")
    {
        s.erase(remove_if(s.begin(), s.end(), (int(*)(int))isspace), s.end());
        s.erase(remove_if(s.begin(), s.end(), (int(*)(int))ispunct), s.end());
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (IsPalindrome(s))
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }
    
}
