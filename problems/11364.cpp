#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, min = 100, max = 0, s;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> s;
            min = (s < min)? s : min;
            max = (s > max)? s : max;
        }
        cout << 2 * (max - min) << '\n';
    }
    
}
