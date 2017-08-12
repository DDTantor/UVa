#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

int main()
{
    ll a;
    vector<ll> A;
    while (cin >> a)
    {;
        A.push_back(a);
        int n = A.size();
        nth_element(A.begin(), A.begin() + n / 2, A.end());    
        ll med = *(A.begin() + n / 2);
        if (!(n % 2))
        {
            nth_element(A.begin(), A.begin() + n / 2 - 1, A.end());
            med = (med + *(A.begin() + n / 2 - 1) ) / 2;
        }
        cout << med << '\n';
    }
    
}
