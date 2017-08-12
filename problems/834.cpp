#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        cout << '[';
        cout << a / b;
        a -= (a / b) * b;
        swap (a, b);
        if (b)
        {
            cout << ';' << a / b;
            a -= (a / b) * b;
            while (a)
            {
                swap(a, b);
                cout << ',' << a / b;
                a -= (a / b) * b;
            }
        }
        cout << "]\n";
        
    }
}
