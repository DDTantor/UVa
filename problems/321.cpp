#include <iostream>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef tuple<int, int, int> state;

int cs, r, d, s, Light[1<<10], V[2][10][1<<10];
vvi G;

int bfs()
{
    queue<state> Q;
    Q.emplace(1, 0, 0);
    V[0][1][0] = 0;
    while (!Q.empty())
    {
        int st, dist, u;
        tie(st, dist, u) = Q.front(); Q.pop();
        bitset<10> X(st);
        if (u == r - 1 && st == (1 << (r - 1)))
            return dist;

        for (int i = 0; i < r; ++i)
        {
            if (i != u && Light[u] & (1 << i) && V[0][u][st ^ (1 << i)] == -1)
            {
                V[0][u][st ^ (1 << i)] = u;
                V[1][u][st ^ (1 << i)] = st;
                Q.emplace(st ^ (1 << i), dist + 1, u);
            }
        }
        
        for (int v : G[u])
        {
            if (!(1 << v & st))
                continue;
            
            if (V[0][v][st] == -1)
            {
                V[0][v][st] = u;
                V[1][v][st] = st;
                Q.emplace(st, dist + 1, v);
            }
        }
    }

    return -1;
}

void print(int u, int state)
{
    if (u == 0 && state == 1)
        return;

    int p = V[0][u][state], pstate = V[1][u][state];
    print(V[0][u][state], V[1][u][state]);
    if (p != u)
        cout << "- Move to room " << u + 1 << ".\n";
    else
        for (int i = 0; i < r ; ++i)
            if ((state ^ pstate) & (1 << i))
                cout << "- Switch " << (state & (1 << i) ? "on " : "off ")
                     << "light in room " << i + 1 << ".\n";
}

int main()
{
    while (cin >> r >> d >> s, r + d + s)
    {
        memset(Light, 0, sizeof Light);
        memset(V, -1, sizeof V);
        cout << "Villa #" << ++cs << '\n';
        G.assign(r, vi());
        int u, v;
        for (int i = 0; i < d; ++i)
        {
            cin >> u >> v, --u, --v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        for (int i = 0; i < s; ++i)
        {
            cin >> u >> v, --u, --v;
            Light[u] += (1 << v);
        }
        
        int steps = bfs();
        if (steps != -1)
        {
            cout << "The problem can be solved in " << steps << " steps:\n";
            print(r - 1, 1 << (r - 1));
            cout << '\n';
        }
        else
            cout << "The problem cannot be solved.\n\n";        
    }
}
