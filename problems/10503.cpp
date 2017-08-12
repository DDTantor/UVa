#include <iostream>

using namespace std;

int m, n, taken[14], L[16], R[16];
bool flag;

void backtrack(int left, int k)
{
    if (k == n)
        flag |= (left == L[1]);
    else
    {
        for (int i = 2; i < m + 2; ++i)
        {
            if (!taken[i])
            {
                taken[i] = true;
                if (left == R[i])
                    backtrack(L[i], k + 1);
                if (left == L[i])
                    backtrack(R[i], k + 1);

                taken[i] = false;
            }
        }
    }
}

int main()
{
    while (cin >> n >> m, n)
    {
        for (int i = 0; i < m + 2; ++i)
            cin >> L[i] >> R[i];
        
        flag = false;
        backtrack(R[0], 0);
        cout << (flag? "YES" : "NO") << '\n';
    }
}
