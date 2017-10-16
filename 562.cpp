#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define inf 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

int t, n, C[100], dp[100][100 * 500];

int val(int id, int r)
{
    if (id == n || r == 0)
        return 0;
    
    if (dp[id][r])
        return dp[id][r];

    if (C[id] > r)
        return val(id + 1, r);

    return dp[id][r] = max(val(id + 1, r), C[id] + val(id + 1, r - C[id]));
}

int main()
{
    cin >> t;
    
    while (cin >> n, t--)
    {
        int sum = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i)
            cin >> C[i], sum += C[i];

        cout << sum - 2 * val(0, sum / 2) << '\n';
    }
}
