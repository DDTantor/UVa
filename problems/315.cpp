#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

int tick;
vb articulation;
vi discovery;
vvi E; 

int dfs(int x, int dad)
{
	discovery[x] = ++tick;
	int low = discovery[x];
	
	articulation[x] = false;
	int children = 0;
	for (int y : E[x])
	{
		if (y == dad) 
			continue;
		if (discovery[y] < 0)
		{
			++children;
			int w = dfs(y, x);
			if (w >= discovery[x]) articulation[x] = true;
			low = min(low, w);
		}
		else
			low = min(low, discovery[y]);
	}
	if (dad == -1) articulation[x] = children > 1;
	
	return low;
}

int main()
{
	int n;
	while (cin >> n, n)
	{
		int u, v;
		E.clear();
		E.resize(n);
		discovery.assign(n, -1);
		articulation.assign(n, false);
		cin.ignore();
		string s;
		while (getline(cin, s), s[0] != '0')
		{
			istringstream iss(s);
			iss >> u;
			while (iss >> v)
			{
				E[u - 1].push_back(v - 1);
				E[v - 1].push_back(u - 1);
			}
		}
		tick = 1;
		for (int i = 0; i < n; ++i)
			if (discovery[i] == -1)
				dfs(i, -1);
				
		cout << count(articulation.begin(), articulation.end(), true) << '\n';
	}
}
