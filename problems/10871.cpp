#include <iostream>

using namespace std;

typedef long long ll;

bool isprime(ll n)
{
    for (ll i = 2; i * i <= n; ++i)
        if (!(n % i))
            return false;

    return true;
}

ll A[10001], B[10000];

int main()
{
    ios::sync_with_stdio(false);
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        A[0] = 0;
        for (int i = 1; i <= n; ++i)
            cin >> A[i], B[i] = A[i], A[i] += A[i - 1];

        int s = 0, best = 0;
        bool flag = 0;
        for (int i = 2; i < n && !flag; ++i)
            for (int j = 1; j + i - 1 <= n && !flag; ++j)
                if (isprime(A[j + i - 1] - A[j - 1]))
                    best = i, s = j, flag = true;
                   
        if (!flag)
            cout << "This sequence is anti-primed.\n";
        else
        {
            cout << "Shortest primed subsequence is length " << best << ":";
            for (int i = 1; i <= best; ++i)
                cout << ' ' << B[i + s - 1];

            cout << '\n';
        }
    }
            
}
