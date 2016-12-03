#include <iostream>

using namespace std;

int main()
{
    int n, m, t;
    cin >> t;
    while (cin >> n >> m, t--)
    {
        int k = (n - 1) / (m - 1);
        if (n - k * (m - 1) != 1)
            cout << "cannot do this\n";
        else
            cout << k << '\n';
    }
    
}
