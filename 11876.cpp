#include <iostream>
#include <algorithm>

using namespace std;

int S[1000000], M = 1000000;

int NOD(int n)
{
    int res = 0;
    for (int i = 1; i * i <= n; ++i)
        if (!(n % i))
            res += (i * i == n? 1 : 2);
    return res;
}

void Fill()
{
    S[0] = 1;
    for (int i = 1; S[i - 1] < M; ++i)
        S[i] = S[i - 1] + NOD(S[i - 1]);
}

int main()
{
    Fill();
    int c = 1, t, A, B;
    cin >> t;
    sort(S, S + M);
    while (cin >> A >> B, t--)
    {
        cout << "Case " << c++ << ": ";
        auto it1 = lower_bound(S, S + M, A);
        auto it2 = upper_bound(S, S + M, B);
        cout << it2 - it1 << '\n';
    }
}
