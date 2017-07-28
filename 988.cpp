#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vvi G;
vi sorted, discovery;

void dfs(int u)
{
	discovery[u] = true;
	for (int v : G[u])
		if (!discovery[v])
			dfs(v);
			
	sorted.push_back(u);
}

int main()
{
	int n, k, v, cs = 0;
	while (cin >> n)
	{
		if (cs++ != 0)
			cout << '\n';
			
		G.clear();
		G.resize(n);
		vi E;
		for (int u = 0; u < n; ++u)
		{
			cin >> k;
			if (k == 0)
				E.push_back(u);
			for (int i = 0; i < k; ++i)
			{
				cin >> v;
				G[u].push_back(v);
			}
		}
		
		sorted.clear(); discovery.clear();
		discovery.assign(n, 0);
		for (int i = 0; i < n; ++i)
			if (!discovery[i])
				dfs(i);
				
		reverse(sorted.begin(), sorted.end());
		vi num(n, 0);
		num[0] = 1;
		
		for (int u : sorted)
			for (int v : G[u])
				num[v] += num[u];
				
		int cnt = 0;
		for (int i : E)
			cnt += num[i];
			
		cout << cnt << '\n';
	}
}
