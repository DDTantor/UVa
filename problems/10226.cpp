#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        int n = 0;
        string s;
        map<string, double> T;
        while (getline(cin, s), !s.empty())
            T[s]++, n++;
            
        for (auto it : T)
            cout << fixed << setprecision(4) << it.first << ' ' << it.second / n * 100 << '\n';
        
        if (t)
            cout << '\n';
    }
}
