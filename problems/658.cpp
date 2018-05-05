#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <vector>
#include <functional>

using namespace std;

typedef pair<int, int> state;
typedef vector<int> vi;

int n, m, T[100], cs, P[2][100][2];

bool Valid(int state, int id)
{
    return ((state & P[0][id][0]) == P[0][id][0])
        && ((~state & P[0][id][1]) == P[0][id][1]); 
}

int Change(int state, int id)
{
    return (state | P[1][id][0]) & ~P[1][id][1];
}

int dijkstra()
{
    vi D(1 << n, 1e9);
    int start = (1 << n) - 1;
    priority_queue<state, vector<state>, greater<state> > PQ;
    PQ.emplace(0, start);
    D[start] = 0;
    while (!PQ.empty())
    {
        int state, dist;
        tie(dist, state) = PQ.top(); PQ.pop();
        if (state == 0)
            return dist;

        if (dist > D[state])
            continue;
        
        for (int i = 0; i < m; ++i)
        {
            int cstate = Change(state, i);
            if (Valid(state, i) && D[cstate] > D[state] + T[i])
                D[cstate] = D[state] + T[i], PQ.emplace(dist + T[i], cstate);
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m && n + m)
    {
        memset(P, 0, sizeof P);
        cout << "Product " << ++cs << '\n';

        string S[2];
        for (int i = 0; i < m; ++i)
        {
            cin >> T[i] >> S[0] >> S[1];
            for (int k = 0; k < 2; ++k)
                for (int j = 0; j < n; ++j)
                    if (S[k][j] == '+' || S[k][j] == '-')
                        (S[k][j] == '+' ? P[k][i][0] : P[k][i][1]) |= (1 << j);
        }

        
        int steps = dijkstra();
        if (steps != -1)
            cout << "Fastest sequence takes " << steps << " seconds.\n\n";
        else
            cout << "Bugs cannot be fixed.\n\n";
    }
}
