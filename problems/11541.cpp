#include <iostream>
#include <cstring>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int n = 1; n <= t; ++n)
    {
        cout << "Case " << n << ": ";   
        string s;
        cin >> s;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            int j = i + 1;
            while(isdigit(s[j + 1]))
                ++j;
                
            fill_n(ostream_iterator<char>(cout), stoi(s.substr(i + 1, j + 1 - i)) , s[i]);
            i = j;
        }
        cout << '\n';
    }
    
}
