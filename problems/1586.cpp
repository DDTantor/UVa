#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string e = "CHON";
    double V[4] = {12.01, 1.008, 16, 14.01};
    int t;
    cin >> t;
    cout << fixed << setprecision(3);
    while (t--)
    {
        string s;
        cin >> s;
        double sum = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            char c = s[i];
            int b = 0;
            while (isdigit(s[i + 1]))
                b *= 10, b += (s[i + 1] - '0'), ++i;
            if (!b)
                b++;
            sum += V[e.find(c)] * b;
        }
        cout << sum << '\n';
    } 
}
