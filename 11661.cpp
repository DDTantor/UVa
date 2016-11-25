#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        string s;
        cin >> s;
        int dist = n;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'Z')
            {
                dist = 0;
                break;
            }
            if (s[i] != '.')
            {
                int j = i + 1;
                while (s[j] == '.' && j < n)
                    j++;
                if (j == n || s[j] == s[i])
                    continue;
                if (j - i < dist)
                    dist = j - i;
            }
        }
        cout << dist << '\n';
        
    }
    
}
