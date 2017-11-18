#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>

using namespace std;

bool dp[31][31][6001], used[6001];
int num[31], sign[31], n;

void solve(int id, int open, int r)
{
    if (dp[id][open][r + 3000])
        return;

    dp[id][open][r + 3000] = true;
    if (id == n)
    {
        used[r + 3000] = true;
        return;
    }

    int v = r + num[id] * sign[id] * ((open % 2 == 0) ? 1 : -1);
    if (sign[id] == -1)
        solve(id + 1, open + 1, v);

    if (open > 0)
        solve(id + 1, open - 1, v);

    solve(id + 1, open, v);
}

int main()
{
    string s;
    char c;
    while (getline(cin, s))
    {
        memset(dp, false, sizeof dp);
        memset(used, false, sizeof used);
        n = 0;
        istringstream iss(s);
        sign[0] = 1;
        while (iss >> num[n++] >> c)
            sign[n] = (44 - c);

        solve(0, 0, 0);

        int res = accumulate(used, used + 6001, 0);
        cout << res << '\n';
    }
}
