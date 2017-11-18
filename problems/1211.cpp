#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

int A[101], n;
double b, r, v, e, f, dp[101][10001], D[10001];

double dist(double d)
{
    double res = 0;
    for (int i = 0; i < d; ++i)
        res += 1 / (v - (i >= r? e * (i - r) : f * (r - i)));

    return res;
}

double solve(int id, int last)
{
    if (id == n - 1)
        return D[A[id] - last];

    if (dp[id][last] != -1)
        return dp[id][last];
    
    return dp[id][last] = min(solve(id + 1, A[id]) + D[A[id] - last] + b ,
                              solve(id + 1, last));
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < 101; ++i)
            for (int j = 0; j < 10001; ++j)
                dp[i][j] = -1.0;
        
        A[0] = 0;
        ++n;
        for (int i = 1; i < n; ++i)
            cin >> A[i];

        cin >> b >> r >> v >> e >> f;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                D[A[j] - A[i]] = dist(A[j] - A[i]);

        cout << fixed << setprecision(4) << solve(0, 0) << '\n';
        
    }
}

    
