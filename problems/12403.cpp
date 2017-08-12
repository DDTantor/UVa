#include <iostream>

using namespace std;

int main()
{
    int t, sum = 0, d;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> s;
        if (s == "donate")
        {
            cin >> d;
            sum += d;
        }
        else
            cout << sum << '\n';
        
    }
}
    
