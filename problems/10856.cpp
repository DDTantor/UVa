#include <iostream>
#include <cstring>
#include <ctgmath>

using namespace std;

typedef long long ll;

const ll maxn = 2703666;

int IsPrime[maxn], Prime[maxn], p, NumFactors[maxn];

void SimpleSieve()
{
    IsPrime[1] = IsPrime[1] = 1;

    for (ll i = 2; i < maxn; ++i)
    {
        if (!IsPrime[i])
        {
            for (ll j = i * i; j < maxn; j += i)
                IsPrime[j] = i;
            
            Prime[p++] = i;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    SimpleSieve();
    for (int i = 2; i < maxn; ++i)
    {
        if (!IsPrime[i])
            NumFactors[i] = 1;
        else
            NumFactors[i] = 1 + NumFactors[i / IsPrime[i]];
    }

    for (int i = 3; i < maxn; ++i)
        NumFactors[i] += NumFactors[i - 1];

    int cs = 1, n;
    while (cin >> n, n >= 0)
    {
        cout << "Case " << cs++ << ": ";
        int lo = 0, hi = maxn;
        if (n == 0) hi = 0;
        while (lo < hi)
        {
            int mid = ceil(0.5 * (lo + hi));
            if (NumFactors[mid] == n)
                lo = hi = mid;
            else if (NumFactors[mid] > n)
                hi = mid - 1;
            else
                lo = mid;
        }

        if (NumFactors[lo] == n)
            cout << lo << "!\n";
        else
            cout << "Not possible.\n";
    }
}
