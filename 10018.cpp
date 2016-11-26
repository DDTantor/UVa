#include <iostream>
#include <string>
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

string Change(string s)
{
    int n = s.length();
    for (int i = 0; i < n / 2; ++i)
        swap(s[i], s[n - i - 1]);
        
    return s;
}

int ToInt(string s)
{
    int a = 0, n = s.length();
    for (int i = 0; i < n; ++i)
    {    
        a *= 10;
        a += (s[i] - '0');
    }
    return a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i = 0;
        do
        {
            long int a = ToInt(s);
            long int b = ToInt(Change(s));
            s = to_string(a + b);
            ++i;
        }while (!IsPalindrome(s));
        cout << i << " " << s << '\n';
    }
}
