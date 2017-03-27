#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

ll GCD(ll a, ll b)
{
    return (b == 0? a : GCD(b, a % b));
}

int main()
{
    int a1, A[1000];
    while (cin >> a1, a1)
    {
        int n = 0; 
        while (cin >> A[n], A[n++]);
        
        ll g = 0;
        for (int i = 0; i < n - 1; ++i)
            g = GCD(g, A[i] - a1);
        
        cout << abs(g) << '\n';
    }
}
