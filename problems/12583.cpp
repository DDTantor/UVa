#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int t, n, k, c = 1;
    string s;
    cin >> t;
    while (cin >> n >> k, t--)
    {
        cout << "Case " << c++ << ": ";
        int cnt = 0;
        cin >> s;
        for (int i = 1; i < s.size(); ++i)
        {
            int r = s.substr(0, i).rfind(s[i]);
            if (r < i && r >= i - k && r != -1)
                cnt++;
        }
        cout << cnt << '\n';
    }
    
}
