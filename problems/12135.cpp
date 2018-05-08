#include <iostream>
#include <unordered_map>
#include <queue>
#include <tuple>
#include <cstring>
#include <bitset>

using namespace std;

typedef tuple<int, int> state;

int t, n, m, Light[1<<15], D[1<<15], q, cs;

int transform(string s)
{
    int res = 0;
    for (char c : s)
    {
        res <<= 1;
        res += (c - '0');
    }

    return res;
}

void bfs()
{
    memset(D, 0, sizeof D);
    queue<state> Q;
    D[0] = 1;
    Q.emplace(1, 0);
    while (!Q.empty())
    {
        int dist, st;
        tie(dist, st) = Q.front(); Q.pop();
        for (int i = 0; i < m; ++i)
        {
            int cst = st ^ Light[i];
            if (!D[cst])
                D[cst] = dist + 1, Q.emplace(dist + 1, cst);
        }
    }
}

int main()
{
    cin >> t;
    while (cin >> n >> m, t--)
    {
        memset(Light, 0, sizeof Light);
        cout << "Case " << ++cs << ":\n";
        for (int i = 0, k; i < m && cin >> k; ++i)
            for (int j = 0, id; j < k && cin >> id; ++j)
                Light[i] += (1 << id);

        bfs();
        string s;
        cin >> q;
        while (q-- && cin >> s)
            cout << D[transform(s)] - 1 << '\n';
        
        cout << '\n';
    }
}
