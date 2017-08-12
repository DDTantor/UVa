#include <iostream>

using namespace std;

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        int n, a, b, low = 0, high = 0;
        cin >> n >> a;
        for (int i = 1; i < n; ++i)
        {
            cin >> b;
            if (a > b) 
                low++;
            else if (a < b)
                high++;
            a = b;
        }
        cout << "Case " << c++ << ": " << high << " " << low << '\n';
    }
    
}
