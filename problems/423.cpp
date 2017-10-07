#include <iostream>

using namespace std;

#define inf 10000

int G[100][100], n;
string s;

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] = (i == j? 0 : inf);
        
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                cin >> s;
                if (s != "x")
                    G[i][j] = G[j][i] = stoi(s);
            }
        }
        
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum = max(sum, G[0][i]);

        cout << sum << '\n';
    }
}
