#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    while (cin.peek() != EOF)
    {
        string t;
        while (getline(cin, t))
        {
            int n = 0;
            for (char c : t)
            {
                if (isdigit(c))
                    n += c - '0';
                else if (c == '!')
                    cout << '\n', n = 0;
                else
                {
                    for (int i = 0; i < n; ++i)
                        cout << (c == 'b'? ' '  : c);

                    n = 0;
                }
            }
            
            cout << '\n';
        }

        if (cin.peek() != EOF)
            cout << '\n';
    }
}
