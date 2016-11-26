#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> M;

bool IsPalindrome(string s)
{
    if (M[s]++)
        return false;
        
    int n = s.length();
    for (int i = 0; i < n; ++i)
        if (s[i] != s[n - i - 1])
            return false;  
                
    return true;
}

int main()
{
    string s;
    int cnt = 0;
    while (cin >> s)
    {
        M.clear();
        int cnt = 0;
        for (int i = 0; i < s.length(); ++i)
            for (int j = i; j < s.length(); ++j)
                if (IsPalindrome(string(s, i, j - i + 1)))
                    cnt++;
                    
        cout << "The string '" << s << "' contains " << cnt << " palindromes.\n";
    }
}
