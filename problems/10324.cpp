#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string str;
    int n, c = 1;
    while (cin >> str)
    {
        cin >> n;
        cout << "Case " << c++ << ":\n";
        for (int k = 0; k < n; ++k)
        {
            int i, j;
            bool flag = true;
            cin >> i >> j;
            for (int l = min(i, j) + 1; l <= max(i, j); ++l)
                if (str[l] != str[l - 1])
                    flag = false;
            if (flag)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }
}
