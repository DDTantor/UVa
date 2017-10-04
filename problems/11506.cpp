#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define inf 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

int M, W, R[100][100], u, v, w, s, t;
vi P;

bool ap()
{
    int k;
    queue<int> Q;
    Q.push(s);
    P.assign(2 * M, -1);
    while (!Q.empty())
    {
        k = Q.front(); Q.pop();
        if (k == t)
            return true;

        for (int x = 0; x < 2 * M; ++x)
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }
    
    return false;
}

int main()
{
    while (cin >> M >> W, M || W)
    {
        s = 0;
        t = M - 1;
        memset(R, 0, sizeof(R));
        R[0][M] = R[M - 1][2 * M - 1] = inf; 
        for (int i = 0; i < M - 2; ++i)
        {
            cin >> u >> w;
            u--;
            R[u][u + M] = w;
        }

        for (int i = 0; i < W; ++i)
        {
            cin >> u >> v >> w;
            u--, v--;
            R[u + M][v] = R[v + M][u] = w;
        }
        
        int m = 0;
        while (ap())
        {
            int aug = inf;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);
            
            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            m += aug;
        }
        
        cout << m << '\n';
    }
}
