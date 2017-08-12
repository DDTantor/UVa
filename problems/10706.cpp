#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ll n, t, SI[40001], SS[40001];
    SI[0] = SS[0] = 0;
    for (int i = 1; i < 40001; ++i)
        SI[i] = SI[i - 1] + log10(i) + 1;
        
    for (int i = 1; i < 40001; ++i)
        SS[i] = SS[i - 1] + SI[i];
    
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll* ind = lower_bound(SS, SS + 40001, n);
        ll sum = *(ind - 1);
        string s = "0";
        while (sum < n)
            s = to_string(1 + atoi(s.c_str())), sum += s.size();
        
        cout << s[s.size()- 1 - (sum - n)] << '\n';
    }
}
