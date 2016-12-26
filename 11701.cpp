#include <iostream>

using namespace std;

int main()
{
    double n;
    while (true)
    {
        cin >> n;
        int d = 0;
        if (n == 1 || n == 0)
            cout << "MEMBER\n";
        else
        {
            while (n *= 3)
            {
                if (d > 6)
                    break;
                if (n >= 1)
                {
                    int c = (int)n;
                    if (c == 1)
                    {
                        cout << "NON-MEMBER\n";
                        break;
                    }
                    n -= c;
                }
                d++;
            }
        }
        if (d > 6)
            cout << "MEMBER\n";
        if (cin.ignore(), cin.peek() == 'E')
            break;
    }
}
