#include <iostream>
#include <cstdint>

using namespace std;

int ToDec(string s)
{
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; ++i)
        res += (s[i] - '0') * ((1 << (n - i)) - 1);
        
    return res;
}

int main()
{
    string s;
    while (cin >> s, s != "0")
        cout << ToDec(s) << '\n';
}
