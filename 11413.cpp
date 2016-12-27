#include <iostream>

using namespace std;

int A[1000], n, m;

bool Try(int x)
{
    int tmp = 0;
    int tren = 0;
    for (int i = 0; i < n; ++i)
    {
        if (A[i] > x)
            return false;
        if (tren + A[i] > x )
            tren = 0;
        if (tren == 0)
            tmp++;
        tren += A[i];
    }
    return tmp <= m;
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        int hi = 1000, lo = 0;
        while (lo < hi)
        {
            if (Try(hi))
                hi = lo + (hi - lo) / 2;
            else
                lo = hi, hi += hi / 2;
        }
        cout << hi + 1 << '\n';
    }
}
