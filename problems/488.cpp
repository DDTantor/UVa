#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, f;
        cin >> a >> f;
        for (int k = 0; k < f; ++k)
        {
            for (int i = -a + 1; i < a; ++i)
            {
                    for (int j = a - abs(i); j > 0; --j)
                        cout << a - abs(i);
                cout << '\n';    
            }
            if (k != f - 1 || t) 
                cout << '\n';
        }
    }
}
