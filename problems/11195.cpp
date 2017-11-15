#include <iostream>

using namespace std;

int cnt, n, cs = 0;
bool rw[30], ld[30], rd[30];
string S[15];

void solve(int c)
{
    if (c == n)
    {
        ++cnt;
        return;
    }
    
    for (int r = 0; r < n; ++r)
    {
        if (!rw[r] && !ld[r - c + n - 1] && !rd[r + c] && S[r][c] != '*')
        {
            rw[r] = ld[r - c + n - 1] = rd[r + c] = true;
            solve(c + 1);
            rw[r] = ld[r - c + n - 1] = rd[r + c] = false;
        }
    }
}

int main()
{
    while (cin >> n, n)
    {
        cout << "Case " << ++cs << ": ";
        for (int i = 0; i < n; ++i)
            cin >> S[i];

        cnt = 0;
        solve(0);
        cout << cnt << '\n';
    }
}
