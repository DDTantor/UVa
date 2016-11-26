#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> M;

bool IsPalindrome(string s)
{
    if (M[s]++)
        return false;
        
    return equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
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
