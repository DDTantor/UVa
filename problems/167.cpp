#include <iostream>
#include <iomanip>

using namespace std;

int t, r[8], G[8][8], best;

bool free(int id, int n)
{
    for (int i = 0; i < n; ++i)
        if (r[i] == id || abs(r[i] - id) == abs(i - n))
            return false;

    return true;
}

void backtrack(int sum, int n)
{
    if (n == 8)
        best = max(best, sum);
    else
        for (int i = 0; i < 8; ++i)
            if (free(i, n))
                r[n] = i, backtrack(sum + G[i][n], n + 1);
}

int main()
{
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 8; ++i)
            for (int j = 0; j < 8; ++j)
                cin >> G[i][j];

        best = 0;
        backtrack(0, 0);
        cout << setw(5) << setfill(' ') << best << '\n';
    }
}
