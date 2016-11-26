#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <algorithm>

using namespace std;

bool IsPalindrome(string s)
{
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
int main()
{
    string s;
    while (getline(cin, s), s != "DONE")
    {
        s.erase(remove_if(s.begin(), s.end(), not1(ref(::isalpha))), s.end());
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        if (IsPalindrome(s))
            cout << "You won't be eaten!\n";
        else
            cout << "Uh oh..\n";
    }
}
