#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
int s, t, R[100][100], P[100];

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

int main()
{
	int n, m, u, v, w, cs = 1;
	while (cin >> n, n)
	{
		cout << "Network " << cs++ << "\nThe bandwidth is ";
		G.clear();
		G.resize(n);
		cin >> s >> t >> m;
		s--; t--;
		memset(R, 0, sizeof(R));
		for (int i = 0; i < m; ++i)
		{
			cin >> u >> v >> w;
			u--; v--;
			G[u].push_back(v);
			G[v].push_back(u);
			R[u][v] += w;
			R[v][u] += w;
		}
		int f = 0;
		while (ap(G))
		{
			int aug = 1000;
			for (int x = t; x != s; x = P[x])
				aug = min(aug, R[P[x]][x]);
				
			for (int x = t; x != s; x = P[x])
				R[P[x]][x] -= aug, R[x][P[x]] += aug;
				
			f += aug;
		}
		cout << f << ".\n\n";
	}
}
