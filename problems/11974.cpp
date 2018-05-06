#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>

using namespace std;

typedef tuple<int, int> state;

int n, m, t, Light[100], V[1<<15], e, cs;

int bfs()
{
    memset(V, 0, sizeof V);
    queue<state> Q;
    Q.emplace(0, 0);
    V[0] = 1;
    while (!Q.empty())
    {
        int dist, st;
        tie(dist, st) = Q.front(); Q.pop();
        
        if (st == e)
            return dist;

        for (int i = 0; i < m; ++i)
        {
            int nstate = st ^ Light[i];
            if (!V[nstate])
                V[nstate] = 1, Q.emplace(dist + 1, nstate);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    while (cin >> n >> m, t--)
    {
        memset(Light, 0, sizeof Light);
        e = (1 << n) - 1;
        cout << "Case " << ++cs << ": ";
        int on;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n && cin >> on; ++j)
                Light[i] |= (on * (1 << j));

        int steps = bfs();
        cout << (steps != -1 ? to_string(steps) : "IMPOSSIBLE") << '\n';
    }
}
