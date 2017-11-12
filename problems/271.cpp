#include <iostream>

using namespace std;

string s, S = "CDEI";
bool solve()
{
    int cnt = 0;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if (s[i] >= 'p' && s[i] <= 'z')
            ++cnt;
        else if (s[i] == 'N')
        {
            if (cnt == 0)
                return false;
        }
        else if (S.find(s[i]) != string::npos)
        {
            if (cnt < 2)
                return false;

            --cnt;
        }
        else
            return false;
                
    }

    return cnt == 1;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> s)
        cout << (solve()? "YES\n" : "NO\n");
}
