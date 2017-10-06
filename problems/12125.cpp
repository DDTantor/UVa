#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

int Q[202][202], R[202][202], s, t;
float d;
vector<vector<int> > G;
vector<int> P;

void add(int a, int b, int w)
{
    G[a].push_back(b);
    G[b].push_back(a);
    Q[a][b] = w;
}

bool ap()
{
    P.assign(s, - 1);
    queue<int> q;
    q.push(s);
    while (!q.empty())
    {
        int k = q.front(); q.pop();
        if (k == t)
            return true;

        for (int x : G[k])
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, q.push(x);
    }

    return false;
}

bool Close(pair<int, int>& a, pair<int, int>& b)
{
    float x = a.first - b.first, y = a.second - b.second;
    return x * x + y * y <= d * d;
}

int main()
{
    int T, n, x, y, m, w;
    cin >> T;
    while (cin >> n >> d, T--)
    {
        s = 2 * n;
        int pen = 0;
        memset(Q, 0, sizeof(Q));
        G.assign(2 * n + 1, vector<int>());
        vector<pair<int, int> > C;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y >> m >> w;
            C.emplace_back(x, y);
            pen += m;
            add(i, i + n, w);
            if (m)
                add(s, i, m);
        }

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (Close(C[i], C[j]))
                    add(i + n, j, 1001), add(j + n, i, 1001);

        bool fl = false;
        for (int i = 0; i < n; ++i)
        {
            t = i;
            memcpy(R, Q, sizeof(Q));
            add(i, t, 1001);
            int flow = 0;
            while (ap())
            {
                int aug = 1001;
                for (int x = t; x != s; x = P[x])
                    aug = min(aug, R[P[x]][x]);

                for (int x = t; x != s; x = P[x])
                    R[P[x]][x] -= aug, R[x][P[x]] += aug;

                flow += aug;
            }

            if (flow == pen)
                cout << (fl? " ": "") << i, fl = true;
        }

        if (!fl)
            cout << "-1";

        cout << '\n';
    }
}
