#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int a = 0;
        for (int i = 0; i < s2.size() && a < s1.size(); ++i)
            a += (s1[a] == s2[i]);
            
        if (a == s1.size())
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
