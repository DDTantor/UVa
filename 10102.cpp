#include <iostream>
#include <vector>
#include <cstring>
#include <climits>

using namespace std;

typedef vector<string> vs;

int main()
{
    int n;
    while (cin >> n)
    {
        vs grid(n);
        for (int i = 0; i < n; ++i)
            cin >> grid[i];

        int M = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == '1')
                {
                    int m = INT_MAX;
                    for (int k = 0; k < n; ++k)
                    {
                        for (int l = 0; l < n; ++l)
                        {
                            if (grid[k][l] == '3')
                            {
                                int dis = abs(i - k) + abs(j - l);
                                m = min(m, dis);
                            }
                        }
                    }
                    M = max(M, m);
                }
            }
        }
        cout << M << '\n';
    }
}
