#include <iostream>
#include <cstring>
#include <climits>

using namespace std;

int t, S, n, V[30001], cVal[100];

int main()
{
    cin >> t;
    while (cin >> S >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> cVal[i];

        for (int i = 0; i <= 30000; ++i)
            V[i] = INT_MAX;

        V[0] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 30000 - cVal[i] ; j >= 0; --j)
                if (V[j] != INT_MAX)
                    V[j + cVal[i]] = min(V[j + cVal[i]], V[j] + 1);

        while (V[S] == INT_MAX)
            S++;
        cout << S << ' ' << V[S] << '\n';
        
    }
}
