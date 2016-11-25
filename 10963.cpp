#include <iostream>

using namespace std;

int main()
{
    int t, W[201];
    cin >> t;
    while (t--)
    {
        int w, a, b;
        cin >> w;
        for (int i = 0; i < w; ++i)
        {
            cin >> a >> b;
            W[i] = a - b;
        }
        bool flag = true;
        for (int i = 1; i < w; ++i)
            if (W[i] != W[i - 1])
                flag = false;
                
        if (flag)
            cout << "yes\n";
        else
            cout << "no\n";
        if (t != 0)
            cout << '\n';
    }
}
