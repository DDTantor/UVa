#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi discovery;
int s = 0, t = 1, R[50][50], P[50];

bool ap(vvi& G)
{
	int k;
	queue<int> Q;
	Q.push(s);
	memset(P, -1, sizeof(P));
	while (!Q.empty())
	{
		k = Q.front(); Q.pop();
		if (k == t)
			return true;
		
		for (int x : G[k])
			if (P[x] == -1 && R[k][x] > 0)
				P[x] = k, Q.push(x);
	}
	return false;
}

void dfs(int u)
{
	discovery[u] = 1;
	for (int v : G[u])
		if (!discovery[v] && R[u][v])
			dfs(v);
}

int main()
{
	int m, n, u, v, w;
	while (cin >> m >> n, m || n)
	{
		 G.clear();
		 G.resize(m);
		 memset(R, 0, sizeof(R));
		 for (int i = 0; i < n; ++i)
		 {
			cin >> u >> v >> w;
			u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
			R[u][v] = R[v][u] = w;
		 }
		 while (ap(G))
		 {
			int aug = INT_MAX;
			for (int x = t; x != s; x = P[x])
				aug = min(aug, R[P[x]][x]);
				
			for (int x = t; x != s; x = P[x])
				R[P[x]][x] -= aug, R[x][P[x]] += aug;
		 }
		 
		 discovery.clear(); discovery.assign(m, 0);
		 dfs(0);
		 for (int v = 0; v < m; ++v)
			if (!discovery[v])
				for (int u : G[v])
					if (!R[u][v] && discovery[u])
						cout << u + 1 << ' ' << v + 1 << '\n';
						
		 cout << '\n';
	}
}
