#include <iostream>
#include <cstring>

using namespace std;


int S, n, W[100], V[100], dp[100][10001];

int val(int ind, int r)
{
    if ((r > S && r <= 1800) || r > S + 200)
        return -6;

    if (ind == n)
    {
        if (r > S && r <= 2000)
            return -6;
        return 0;
    }
    
    if (dp[ind][r])
        return dp[ind][r];
    
    return dp[ind][r] = max(val(ind + 1, r), V[ind] + val(ind + 1, r + W[ind]));
}

int main()
{
    while (cin >> S >> n)
    {
        memset(dp, 0, sizeof(dp));
        bool flag = false;
        for (int i = 0; i < n; ++i)
            cin >> W[i] >> V[i];

        cout << val(0, 0) << '\n'; 
    }
}
