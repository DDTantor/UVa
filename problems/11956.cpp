#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int M[100] = {0};
        int curr = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            switch(s[i])
            {
                case '<':
                    curr--;
                    if (curr < 0)
                        curr = 99;
                    break;
                case '>':
                    curr++;
                    if (curr > 99)
                        curr = 0;
                    break;
                case '+':
                    M[curr]++;
                    if (M[curr] > 255)
                        M[curr] = 0;
                    break;
                case '-':
                    M[curr]--;
                    if (M[curr] < 0)
                        M[curr] = 255;
            }
        }
        cout << "Case " << c++ << ":";
        for (int i = 0; i < 100; ++i)
            printf(" %02X", M[i]);
        
        cout << '\n';
    }
}
