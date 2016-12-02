#include <iostream>

using namespace std;

int main()
{
    string s;
    int a = 0;
    while (cin >> s)
    {
        if (a++)
            cout << '\n';
        bool l, h, b, w4,w100;
        int sum3 = 0, sum11 = 0, pr = -1, n = s.size() - 1;
        for (char i : s)
            sum3 += (i - '0'), sum11 += pr * (i - '0'), pr = -pr; 
        w100 = (s[n - 1] == '0' && s[n] == '0');
        w4 = !(((s[n - 1] - '0') * 10 + s[n] - '0') % 4);    
        l = (w4 && !w100) || 
            (w100 && !(((s[n - 3] - '0') * 10 + s[n - 2] - '0') % 4));
        h = (!(sum3 % 3) && (s[n] == '5' || s[n] == '0'));
        b = (!(sum11 % 11) && (s[n] == '5' || s[n] == '0') && l);
        if (!h && !l)
            cout << "This is an ordinary year.\n";    
        if (l)
            cout << "This is leap year.\n";
        if (h)
            cout << "This is huluculu festival year.\n";
        if (b)
            cout << "This is bulukulu festival year.\n";
    }
}
