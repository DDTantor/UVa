#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <tuple> 
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<char> vc;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    string awaken;
    char a, b;
    while (cin >> n >> m >> awaken)
    {
        G.assign(n, vi());
        vc W(n);
        unordered_map<char, int> M;
        int k = 0;
        for (char c : awaken)
            M[c] = k++;
        
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            auto p = M.emplace(a, k);
			if (p.second) W[k++] = a;
			auto q = M.emplace(b, k);
			if (q.second) W[k++] = b;
			int x = p.first->second;
            int y = q.first->second;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        queue<ii> Q;
        vi V(k, 0);
        for (char c : awaken)
            Q.emplace(0, M[c]), V[M[c]] = 4;

        int res = 0;
        while (!Q.empty())
        {
            int d, u;
            tie(d, u) = Q.front(); Q.pop();
            res = max(d, res);
            for (int v : G[u])
            {
                if (V[v] < 3)
                    V[v]++;
                if (V[v] == 3)
                    Q.emplace(d + 1, v), V[v]++;
            }
        }

        if (count_if(V.begin(), V.end(), [](int a) {return a == 4;}) == n)
            cout << "WAKE UP IN, " << res << ", YEARS\n";
        else
            cout << "THIS BRAIN NEVER WAKES UP" << '\n';
    }
}
