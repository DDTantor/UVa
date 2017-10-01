#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

int main()
{
    string s;
    while (getline(cin, s))
    {
        vll C, X;
        ll c;
        istringstream iss(s);
        while (iss >> c)
            C.push_back(c);

        getline(cin, s);
        iss.clear();
        iss.str(s);
        while (iss >> c)
            X.push_back(c);

        for (int i = 0; i < X.size(); ++i)
        {
            ll sum = C[0];
            for (int j = 1; j < C.size(); ++j)
                sum = X[i] * sum + C[j];
            
            cout << sum << (i == X.size() - 1? '\n' : ' ');
        }
    }
}
