#include <iostream>
#include <string>

using namespace std;

bool isvowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    string s;
    string v = "AaEeIiOoUu";
    while (getline(cin, s))
    {
        int j = 0;
        s = s + " ";
        for (int i = 0; i < s.size(); ++i)
        {
            if (!isalpha(s[i]))
            {
                string a = s.substr(j, i - j);
                j = i + 1;
                int n = a.size();
                if (isvowel(a[0]))
                    cout << a;
                else
                {
                    for (int k = 1; k <= n; ++k)
                        cout << a[k % n];
                }
                if (a.size())
                    cout << "ay";
                     
                if (i != s.size() - 1) 
                    cout << s[i];
            }
        }
        cout << '\n'; 
    }
}
