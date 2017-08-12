#include <iostream>

using namespace std;

int main()
{
    int t;
    string L[3] = {"one", "two", "three"};
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < 3; ++i)
        {
            int cnt = 0;
            if (s.size() != L[i].size())
                continue;
            for (int j = 0; j < s.size(); ++j)
                if (s[j] == L[i][j])
                    cnt++;
            if (cnt + 1 >= L[i].size())
            {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
}
