#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
#include <cstring>

using namespace std;

typedef tuple<int, int, int> state;

int n, G[100][100], cs, s1, s2, e, V[100][100];

int bfs()
{
    memset(V, 0, sizeof V);
    queue<state> Q;
    Q.emplace(0, s1, s2);
    V[s1][s2] = 0;
    while (!Q.empty())
    {
        int dist, p1, p2;
        tie(dist, p1, p2) = Q.front(); Q.pop();
        if (p1 == e || p2 == e)
            return dist;

        if (dist > 100 * 100)
            return -1;
        
        for (int i = 0; i < n; ++i)
            if (G[p1][i] && i == p2 && !V[G[p1][i] - 1][p2])
                V[G[p1][i] - 1][p2] = 1, Q.emplace(dist + 1, G[p1][i] - 1, p2);

        for (int i = 0; i < n; ++i)
            if (G[p2][i] && i == p1 && !V[p1][G[p2][i]])
                V[p1][G[p2][i] - 1] = 1, Q.emplace(dist + 1, p1, G[p2][i] - 1);
    }

    return -1;
}

int main()
{
    while (cin >> n, n)
    {
        cout << "Game #" << ++cs << '\n';
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> G[i][j];

        cin >> s1 >> s2 >> e;
        --s1, --s2, --e;
        int steps = bfs();
        if (steps != -1)
            cout << "Minimum Number of Moves = " << steps << "\n\n";
        else
            cout << "Destination is Not Reachable !\n\n";
    }
}
