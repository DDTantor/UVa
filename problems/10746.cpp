#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <iomanip>
#include <queue>
#include <cmath>

using namespace std;

#define inf 1e9

typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vi> vvi;

const int MAX = 42;

int R[MAX][MAX], V, E, s, t;
double C[MAX][MAX];
vi P;
vd dist;
vvi G;

bool ap()
{
    queue<int> Q;
    Q.push(s);
    P.assign(V, -1);
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

int HasCycle()
{
    dist.assign(V, inf);
    P.assign(V, -1);
    dist[t] = 0;
    for (int k = 0; k < V - 1; ++k)
        for (int u = 0; u < V; ++u)
            for (int v : G[u])
                if (R[u][v] > 0 && dist[v] > dist[u] + C[u][v])
                    dist[v] = dist[u] + C[u][v], P[v] = u;

    bool fl;
    for (int u = 0; u < V; ++u)
        for (int v : G[u])
            if (R[u][v] > 0 && dist[v] > dist[u] + C[u][v])
                fl = true;

    if (fl)
    {
        vi vis(V, 0);
        int x = s;
        vis[x] = true;
        for (int i = 0; i < V; ++i)
        {
            x = P[x];
            if (x == -1)
                return -1;
            
            if (vis[x])
                return x;
            
            vis[x] = true;
        }
    }
    
    return -1;
}

id MinCostMaxFlow()
{
    int u, MF = 0;
    double MC = 0.0;
    while (ap())
    {
        int aug = inf;
        for (int x = t; x != s; x = P[x])
            aug = min(aug, R[P[x]][x]);

        for (int x = t; x != s; x = P[x])
            R[P[x]][x] -= aug, R[x][P[x]] += aug, MC += C[P[x]][x] * aug;

        MF += aug;
    }

    while (u = HasCycle(), u != -1)
    {
        int aug = R[P[u]][u];

        for (int x = P[u]; x != u; x = P[x])
            aug = min(aug, R[P[x]][x]);
        
        R[P[u]][u] -= aug;
        R[u][P[u]] += aug;
        MC += C[P[u]][u] * aug;
        for (int x = P[u]; x != u; x = P[x])
            R[P[x]][x] -= aug, R[x][P[x]] += aug, MC += C[P[x]][x] * aug;
    }
    
    return {MF, MC};
}

void process(int u, int v, int w, double c)
{
    R[u][v] = w;
    C[u][v] = c, C[v][u] = -c;
    G[u].push_back(v);
    G[v].push_back(u);
}

int main()
{
    int n, m;
    while (cin >> n >> m, n || m)
    {
        memset(R, 0, sizeof(R));
        memset(C, 0, sizeof(C));
        V = n + m + 2;
        s = n + m;
        t = s + 1;
        G.assign(V, vi());
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                double c;
                cin >> c;
                process(j, m + i, 1, c);
            }
        }
        for (int i = 0; i < n; ++i)
            process(m + i, t, 1, 0);

        for (int i = 0; i < m; ++i)
            process(s, i, 1, 0);

        int MF;
        double MC;
        tie(MF, MC) = MinCostMaxFlow();
        cout << fixed << setprecision(2) << round(100 * MC / n) / 100 << endl;
    }
}
