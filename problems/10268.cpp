#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main()
{
    ll x, c;
    while (cin >> x)
    {
        cin.ignore();
        string s;
        vi C;
        getline(cin, s);
        istringstream iss(s);
        while (iss >> c)
            C.push_back(c);
      
        ll n = C.size() - 1, sum = 0;
        for (int i = 0; i < C.size() - 1; ++i)
            sum = x * sum  + (n - i) * C[i];
        
        cout << sum << '\n';
    }
}
