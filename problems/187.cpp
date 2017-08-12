#include <iostream>
#include <string>
#include <utility>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include <tuple>
#include <functional>
#include <numeric>

using namespace std;

#define MP make_pair

typedef pair<string, double> si;

int main()
{
    string s, s1(3, 0), s2;
    map<string, vector<si>> T;
    map<string, string> S;
    double c;
    
    while (getline(cin.read(&s1[0], 3), s2), s1 != "000")
        S[s1] = s2;
    
    while (cin.read(&s1[0], 3) >> s2 >> c, s1 != "000")
    {
        cin.ignore();
        T[s1].push_back(MP(s2, c / 100.0));
    }
    cout << fixed << setprecision(2);
    for (auto i = T.begin(); i != T.end(); ++i)
    {
        double balance = accumulate(i->second.begin(), i->second.end(), 
        0.0, [](double a, si b){return a + b.second;});
       
        if (balance != 0)
        {
            cout << "*** Transaction " << i->first << " is out of balance ***\n";
            for (int j = 0; j < i->second.size(); ++j)
            {
                string num;
                tie(num, c) = i->second[j];
                cout << num << " " << S[num] << " " << setw (40 - S[num].size()) << c << '\n';
            }
            cout << "999 Out of Balance " << setw (26) << -balance << "\n\n";
        }   
    }
    return 0;
}
