#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;

ll Sigma(ll n)
{
    ll res = 0;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (!(n % i))
        {
            res += i;
            if (i * i != n)
                res += n / i;
        }
    } 
    return res;
}

int main()
{
    ll A[1001], n, c = 1;
    memset(A, -1, sizeof(A));
    for (int i = 1; i <= 1000; ++i)
    {
        n = Sigma(i);
        if (n <= 1000)
            A[n] = i;
    }
    
    while (cin >> n, n)
        cout << "Case " << c++ << ": " << A[n] << '\n';
        
}
