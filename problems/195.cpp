#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(char a, char b)
{
    char la = tolower(a);
    char lb = tolower(b);
    if (la == lb)
        return a < b;
        
    return la < lb;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end(), cmp);
        cout << s << '\n';
        while (next_permutation(s.begin(), s.end(), cmp))
            cout << s << '\n';
    }
    
}
