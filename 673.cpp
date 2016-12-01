#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        stack<char> M;
        string s;
        getline(cin, s);
        for (auto i : s)
        {
            if (i == '[' || i == '(')
                M.push(i);
            else if (!M.empty() && 
                    (char(i - 2) == M.top() || char(i - 1) == M.top()))
                M.pop();
            else 
                goto stop;
        }
        
        if (M.empty())
            cout << "Yes\n";
        else
            stop : cout << "No\n";
            
    }
}
