#include <iostream>
#include <climits>
#include <cmath>
#include <cstring>

using namespace std;

int row[8], nw[8], best, cs = 1;

bool place(int r, int c)
{
    for (int i = 0; i < c; ++i)
        if (nw[i] == r || (abs(nw[i] - r) == abs(i - c)))
            return false;

    return true;
}

void backtrack(int c, int p)
{
    if (c == 8)
        best = min(p, best);

    else
        for (int i = 0; i < 8; ++i)
            if (place(i, c))
                nw[c] = i, backtrack(c + 1, p + (i != row[c]));
    }

int main()
{
    
    while (cin.peek() != EOF)
    {
        for (int i = 0; i < 8; ++i)
            cin >> row[i], row[i]--;

        memset(nw, 0, sizeof(nw));
        best = INT_MAX;
        backtrack(0, 0);
        cout << "Case " << cs++ << ": " << best  << '\n';
        cin.ignore();
    }
}
