#include <iostream>

using namespace std;

int main()
{
    int t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        int i = s.size() - 1;
        
        if (s == "1" || s == "4" || s == "78")
            cout << "+\n";
        else if (i > 0 && s[i] == '5' && s[i - 1] == '3')
            cout << "-\n";
        else if (i > 1 && s[0] == '9' && s[i] == '4')
            cout << "*\n";
        else
            cout << "?\n";
    }
}
    
