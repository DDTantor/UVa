#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;

viii sol;
int n, G[100][100], x, y, z;

bool WinTie(int i, int j, int k)
{
    return ((i < j && j < k) || (i > j && j > k)) && (G[i][j] + G[j][k] + G[k][i] == 3);
}

bool Tie(int i, int j, int k)
{
    return (i < j && j < k) && (G[i][j] + G[j][i] + G[i][k] + G[k][i] + G[j][k] + G[k][j] == 0);
}

int main()
{
    while (cin >> n)
    {
        memset(G, 0, sizeof(G));
        sol.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> G[i][j];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < n; ++k)
                    if (WinTie(i, j, k) || Tie(i, j, k))
                        sol.emplace_back(i, j, k);

        cout << sol.size() << '\n';
        for (iii k : sol)
        {
            tie (x, y, z) = k;
            cout << x + 1 << ' ' << y + 1 << ' ' << z + 1 << '\n';
        }
    }
}
