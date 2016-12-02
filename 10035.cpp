#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b, a || b)
    {
        int c = 0, cnt = 0;
        while (a || b)
        {
            c = (a % 10 + b % 10 + c) / 10;
            if (c) cnt++;
            a /= 10;
            b /= 10;
        }
        if (!cnt)
            cout << "No";
        else
            cout << cnt;
        cout << " carry operation" << ((cnt > 1)? "s.\n" : ".\n");
    }
    
    
}
