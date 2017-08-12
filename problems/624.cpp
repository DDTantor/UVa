#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<bool> vb;

int g, best, A[20], n;
vb sol, taken;

void backtrack(int sum, int c)
{
    if (c == n && sum > best && sum <= g)
            best = sum, sol = taken;
    else if (c < n)
    {
        taken[c] = true, backtrack(sum + A[c], c + 1);
        taken[c] = false, backtrack(sum, c + 1);
    }
}

int main()
{
    while (cin >> g >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        best = 0;
        sol.assign(n, false); 
        taken.assign(n, false);
        backtrack(0, 0);
        for (int i = 0; i < n; ++i)
            if (sol[i])
                cout << A[i] << ' ';

        cout << "sum:" << best << '\n';
    }
}
