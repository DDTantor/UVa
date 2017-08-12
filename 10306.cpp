#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int main()
{
    int cVal[2][40], V[301][301];
    int n, m, S, a, b;
    cin >> n;
    while (cin >> m >> S, n--)
    {
        for (int i = 0; i < m; ++i)
            cin >> cVal[0][i] >> cVal[1][i];

        for (int i = 0; i <= S; ++i)
            for (int j = 0; j <= S; ++j)
                V[i][j] = 302 * 302;

        V[0][0] = 0;
        for (int i = 0; i < m; ++i)
            for (int j = cVal[0][i]; j <= S; ++j)
                for (int k = cVal[1][i]; k <= S; ++k)
                    V[j][k] = min(V[j][k], 1 + V[j - cVal[0][i]][k - cVal[1][i]]);

        int res = 302 * 302;
        for (int i = 0; i <= S; ++i)
            for (int j = 0; j <= S; ++j)
                if (i * i + j * j == S * S)
                    res = min(res, V[i][j]);
        
        if (res == 302 * 302)
            cout << "not possible\n";
        else
            cout << res << '\n';
    }
}
