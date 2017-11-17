#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define inf 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

const int MAX = 50;

int R[MAX][MAX], V, E, s, t;
string S[6] = {"XS", "S", "M", "L", "XL", "XXL"}; 
vvi G;
vi P;

bool AP()
{
    queue<int> Q;
    P.assign(V + 8, -1);
    Q.push(s);
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

void process(int u, int v, int w)
{
    G[u].push_back(v);
    G[v].push_back(u);
    R[u][v] = w; 
}

int main()
{
    int c, n;
    cin >> c;
    while (cin >> n >> V, c--)
    {
        s = 0, t = 1; 
        memset(R, 0, sizeof(R));
        G.assign(V + 8, vi());
        for (int i = 2; i <= 7; ++i)
            process(s, i, n / 6);

        string a;
        for (int i = 0; i < V; ++i)
        {
            for (int k = 0; k < 2; ++k)
                cin >> a, process(find(S, S + 6, a) - S + 2, 8 + i, 1);

            process(8 + i, t, 1);
        }
        
        int MF = 0;
        while (AP())
        {
            int aug = inf;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);

            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            MF += aug;
        }

        cout << (MF == V? "YES\n" : "NO\n");
    }
}
