#include <iostream>
#include <queue>
#include <utility>
#include <sstream>
#include <vector>
#include <cstring>
#include <tuple>

using namespace std;

typedef pair<int ,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;

vvii G;
int M[500], n, d, T[5], f, u, w, v;

int dijkstra()
{
    vi D(500, 160 * 100);
    priority_queue<ii, vii, greater<ii> > PQ;
    int s = -1;
    for (int i = 0; i < n; ++i)
        if (M[100 * i])
            s = i;
    if (s == -1)
        return -1;
    D[100 * s] = 0;
    PQ.emplace(0, 100 * s);
    while (!PQ.empty())
    {
        tie(w, u) = PQ.top(); PQ.pop();
        if (w > D[u])
            continue;
        for (ii t : G[u])
            if (t.first + D[u] < D[t.second])
                D[t.second] = D[u] + t.first, PQ.emplace(D[t.second], t.second);
        
    }
    int best = 160 * 100;
    for (int i = 0; i < n; ++i)
        best = min(best, D[100 * i + d]);

    return best == 160 * 100? -1 : best;
}

int main()
{
    while (cin >> n >> d)
    {
        G.assign(500, vii());
        memset(M, 0, sizeof(M));
        for (int i = 0; i < n; ++i)
            cin >> T[i];
        
        string s;
        cin.ignore();
        for (int i = 0; i < n; ++i)
        {
            getline(cin, s);
            istringstream iss(s);
            while (iss >> f)
                M[100 * i + f] = 1;
            
            int prev = -1;
            for (int j = 0; j < 100; ++j)
            {
                if (prev == -1 && M[100 * i + j])
                    prev = j;
                else if (M[100 * i + j])
                {
                    G[100 * i + prev].emplace_back(T[i] * (j - prev), 100 * i + j);
                    G[100 * i + j].emplace_back(T[i] * (j - prev), 100 * i + prev);
                    prev = j;
                }
            }
        }
        
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (i == 0 && M[100 * j + i] && M[100 * k + i])
                    {
                        G[100 * j + i].emplace_back(0, 100 * k + i);
                        G[100 * k + i].emplace_back(0, 100 * j + i);
                    }
                    else if (M[100 * j + i] && M[100 * k + i])
                    {
                        G[100 * j + i].emplace_back(60, 100 * k + i);
                        G[100 * k + i].emplace_back(60, 100 * j + i);
                    }
                }
            }
        }
        /*for (int i = 0; i < 500; ++i)
        {
            if (G[i].size())
            {
                for (ii t : G[i])
                    cout << "OD " << i << " DO " << t.second << " ZA " << t.first << endl;
                cout << endl;
            }
            }*/
        int t = dijkstra();
        if (t == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << t << '\n';
    }
}
