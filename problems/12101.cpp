#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> state;

int IsPrime[10000], Prime[10000], id[10000], p, a, b, t, d;
vector<vector<int> > G;
vector<int> V;


void SimpleSieve()
{
    IsPrime[1] = 1;

    for (int i = 2; i < 10000; ++i)
    {
        if (!IsPrime[i])
        {
            for (int j = i * i; j < 10000; j += i)
                IsPrime[j] = 1;

            if (i > 1000)
                id[i] = p, Prime[p++] = i;
        }
    }
}

bool check(int u, int v, bool flag = false)
{
    int cnt = 0;
    while (u || v)
    {
        cnt += (u % 10 != v % 10);        
        u /= 10, v /= 10;
    }

    return cnt == 1;
}

void build()
{
    G.assign(p, vector<int>());
    for (int i = 0; i < p; ++i)
        for (int j = 0; j < p; ++j)
            if (check(Prime[i], Prime[j]))
                G[i].push_back(j), G[j].push_back(i);
}

string bfs()
{
    queue<state> Q;
    Q.emplace(a, 0);
    V.assign(p, 0);
    while (!Q.empty())
    {
        int st, tm;
        tie(st, tm) = Q.front(); Q.pop();
        if (st == b)
            return to_string(tm);
        
        for (int v : G[id[st]])
            if (!V[v])
                V[v] = 1, Q.emplace(Prime[v], tm + 1);
    }

    return "Impossible";
}

int main()
{
    SimpleSieve();
    build();
    cin >> t;
    while (cin >> a >> b, t--)
        cout << bfs() << '\n';
}
