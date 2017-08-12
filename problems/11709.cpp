#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

typedef vector<string > vs;
typedef vector<int> vi;
typedef vector<vi> vvi;

vi num, low, S, discovery;
vvi G;
vs W;
int SCC, cnt;

void tarjan(int u)
{
	low[u] = num[u] = cnt++;
	S.push_back(u);
	discovery[u] = 1;
	for (int j = 0; j < G[u].size(); ++j)
	{
		int v = G[u][j];
		if (num[v] == -1)
			tarjan(v);
		if (discovery[v])
			low[u] = min(low[u], low[v]);
	}
	
	if (low[u] == num[u])
	{
		SCC++;
		while (true)
		{
			int v = S.back(); S.pop_back(); discovery[v] = 0;
			if (u == v) break;
		}
	}
}

int main()
{
	int p, t;
	while (cin >> p >> t, p || t)
	{
		cin.ignore();
		string a, b;
		G.clear();
		W.clear();
		unordered_map<string, int> M;
		W.resize(p);
		G.resize(p);
		for (int i = 0; i < p; ++i)
			getline(cin, a);
		int k = 0;
		for (int i = 0; i < t; ++i)
		{
			getline(cin, a);
			getline(cin, b);
			auto p = M.emplace(a, k);
			if (p.second) W[k++] = a;
			auto q = M.emplace(b, k);
			if (q.second) W[k++] = b;
			int x = p.first->second;
			int y = q.first->second;
			G[x].push_back(y);
		}
		num.assign(p, -1); low.assign(p, 0); discovery.assign(p, 0);
		cnt = SCC = 0; 
		for (int i = 0; i < p; ++i)
			if (num[i] == -1)
				tarjan(i);
		cout << SCC << '\n';
	}
}
