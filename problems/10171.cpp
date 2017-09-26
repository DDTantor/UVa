#include <iostream>
#include <cstring>

using namespace std;

#define MAX 26 * 501

int M[26][26], Y[26][26], n, w, best, res;
bool used[26];
char a, b, u, v, s, e;

int main()
{
    while (cin >> n, n)
    {
        memset(used, false, sizeof(used));
        for (int i = 0; i < 26; ++i)
            for (int j = 0; j < 26; ++j)
                M[i][j] = Y[i][j] = (i == j? 0 : MAX);
        
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b >> u >> v >> w;
            if (v == u)
                continue;
            (a == 'Y'? Y[u - 'A'][v - 'A'] : M[u - 'A'][v - 'A']) = w;
            if (b == 'B')
                (a == 'Y'? Y[v - 'A'][u - 'A'] : M[v - 'A'][u - 'A']) = w;
        }
        
        for (int k = 0; k < 26; ++k)
        {
            for (int i = 0; i < 26; ++i)
            {
                for (int j = 0; j < 26; ++j)
                {
                    M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
                    Y[i][j] = min(Y[i][j], Y[i][k] + Y[k][j]);
                }
            }
        }
        cin >> s >> e;
        res = MAX;
        for (int i = 0; i < 26; ++i)
            if (Y[s - 'A'][i] != MAX && M[e - 'A'][i] != MAX && res > Y[s - 'A'][i] + M[e - 'A'][i])
                res = Y[s - 'A'][i] + M[e - 'A'][i], best = i;

        used[best] = true;
        for (int i = 0; i < 26; ++i)
            if (Y[s - 'A'][i] + M[e - 'A'][i] == res)
                used[i] = true;
        if (res != MAX)
        {
            cout << res;
            for (int i = 0; i < 26; ++i)
                if (used[i])
                    cout << ' ' << char('A' + i);
        }
        else
            cout << "You will never meet.";

        cout << '\n';
    }                
}
