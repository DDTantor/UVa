#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi discovery;

int dfs(int u)
{
	discovery[u] = 1;
	int c = 0;
	for (int v : G[u])
		if (!discovery[v])
			c += 1 + dfs(v);
	return c;
}

int main()
{
	int n, u, k, v;
	while (cin >> n, n)
	{
		G.clear();
		G.resize(n);
		vi In(n, 0), num(n, 0);
		for (int u = 0; u < n; ++u)
		{
			cin >> k;
			for (int i = 0; i < k; ++i)
			{
				cin >> v;
				G[u].push_back(v - 1);
			}
		}
		
		int Mi = 0, M = 0;
		for (int i = 0; i < n; ++i)
		{
			discovery.clear(); 
			discovery.assign(n, 0);
			int c = dfs(i);
			if (c > M)
				Mi = i, M = c;
		}
		cout << Mi + 1 << '\n';
	}
}

