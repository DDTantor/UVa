#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

#define MP make_pair

typedef pair<string, double> si;

int main()
{
    string s;
    map<string, vector<si>> T;
    map<string, string> S;
    double c;
    while(getline(cin, s), string(s.begin(), s.begin() + 3) != "000" )
        S[string(s.begin(), s.begin() + 3)] = string(s.begin() + 3, s.end());
    
    while(cin >> s >> c, string(s.begin(), s.begin() + 3) != "000")
        T[string(s.begin(), s.begin() + 3)].push_back(MP(string(s.begin() + 3, s.end()), c / 100.0));
    cout << fixed << setprecision(2);
    for (auto i = T.begin(); i != T.end(); ++i)
    {
        double balance = 0;
        for (int j = 0; j < i->second.size(); ++j)
            balance += i->second[j].second;
        
        if (balance != 0)
        {
            cout << "*** Transaction " << i->first << " is out of balance ***\n";
            for (int j = 0; j < i->second.size(); ++j)
            {
                string num = i->second[j].first;
                c = i->second[j].second;
                cout << num << " " << S[num] << " " << setw (10 + 30 - S[num].size()) << c << '\n';
            }
            cout << "999 Out of Balance " << setw (26) << -1.0 * balance << "\n\n";
        }   
    }
    return 0;
}
