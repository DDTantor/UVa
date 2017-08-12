#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int sum = 0;
        int r = 0;
        for (auto i : s)
        {
            if (i == 'O')
                r++;
            else
                r = 0;
            sum += r;
        }
        cout << sum << endl;
    }
}
