#include <iostream>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int pred = 1;
        char c = 'x';
        string a;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> a;
            if (a == "No")
                continue;
            
            if (c == 'x' && a[0] == '-') pred *= -1;
            else if (c == 'y' && a[1] == 'y' && a[0] == '+') pred *= -1;
            else if (c == 'z' && a[1] == 'z' && a[0] == '+') pred *= -1;    
            
            if (c == 'x') c = a[1];
            else if (c == 'z' && a[1] == 'z') c = 'x';
            else if (c == 'y' && a[1] == 'y') c = 'x';
            
        }
        cout << ((pred > 0)? '+' : '-') << c << '\n';
    }
    
}
