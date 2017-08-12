#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sstream>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int tick;
vi discovery;
vii bridges;
vvi E; 

int dfs(int x, int dad)
{
	discovery[x] = ++tick;
	int low = discovery[x];
	
	int children = 0;
	for (int y : E[x])
	{
		if (y == dad) 
			continue;
		if (discovery[y] < 0)
		{
			++children;
			int w = dfs(y, x);
			if (w > discovery[x]) bridges.push_back(minmax({x, y}));
			low = min(low, w);
		}
		else
			low = min(low, discovery[y]);
	}
	
	return low;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int u, v, k;
		E.clear();
		E.resize(n);
		discovery.assign(n, -1);
		bridges.clear();
		cin.ignore();
		string s, a;
		for (int i = 0; i < n; ++i)
		{
			getline(cin, s);
			istringstream iss(s);
			iss >> u >> a;
			while (iss >> v)
			{
				E[u].push_back(v);
				E[v].push_back(u);
			}
		}
		tick = 1;
		for (int i = 0; i < n; ++i)
			if (discovery[i] == -1)
				dfs(i, -1);
				
		sort(bridges.begin(), bridges.end());
		cout << bridges.size() << " critical links\n";
		for (ii p : bridges)
			cout << p.first << " - " << p.second << '\n';
		cout << endl;
	}
}
