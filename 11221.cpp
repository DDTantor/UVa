#include <string>
#include <stdio.h>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, root;

bool IsPalindrome(string s)
{
    for (int i = 0; i < n; ++i)
        if (s[i] != s[n - i - 1])
            return false;  
                
    return true;
}

bool ReIsPalindrome(string s)
{
    for (int i = 0; i < root; ++i)
        for (int j = 0; j < root; ++j)
            if (s[j * root + i] != s[n - (j * root + i) - 1])
                return false;
    
    return true;
}

bool IsMagic(string s)
{
    if (!IsPalindrome(s))
        return false;
    if (!ReIsPalindrome(s))
        return false;
    return true;
}

int main()
{
    int t, c = 1;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string s;
        getline(cin, s);
        s.erase(remove_if(s.begin(), s.end(), (int(*)(int))isspace), s.end());
        s.erase(remove_if(s.begin(), s.end(), (int(*)(int))ispunct), s.end());
        n = s.length();
        root = round(sqrt(n));
        cout << "Case #" << c++ << ":\n";
        if (n == root * root && IsMagic(s))
            cout << root << '\n';
        else
            cout << "No magic :(\n";
        
    }
    
}
