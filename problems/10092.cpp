#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define inf 1e9

int s, t, nk, np, kat, n, w, R[1022][1022];
vector<vector<int> > G;
vector<int> P;

bool ap()
{
    queue<int> Q;
    Q.push(s);
    P.assign(nk + np + 2, -1);
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == t)
            return true;

        for (int x : G[k])
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }

    return false;
}

void add(int a, int b, int w)
{
    R[a][b] = w;
    G[a].push_back(b);
    G[b].push_back(a);
}

int main()
{
    while (cin >> nk >> np, nk || np)
    {
        memset(R, 0, sizeof(R));
        G.assign(nk + np + 2, vector<int>());
        s = nk + np, t = nk + np + 1;
        int sum = 0;
        for (int i = 0; i < nk; ++i)
            cin >> w, add(i, t, w), sum += w;
                
        for (int i = 0; i < np; ++i)
        {
            add(s, i + nk, 1);
            cin >> n;
            for (int j = 0; j < n; ++j)
                cin >> kat, add(nk + i, kat - 1, inf);
        }
        
        int flow = 0;
        while (ap())
        {
            int aug = inf;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);

            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            flow += aug;
        }
        
        if (flow == sum)
        {
            cout << "1\n";
            for (int i = 0; i < nk; ++i)
            {
                bool flag = false;
                for (int j : G[i])
                    if (R[i][j] > 0)
                        cout << (flag? " " : "") << j - nk + 1, flag = true;
                
                cout << '\n';
            }
        }
        else
            cout << "0\n";
    }
}
