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
		while (true)
		{
			int v = S.back(); S.pop_back(); discovery[v] = 0;
			cout << W[v];
			if (u == v) break;
			cout << ", ";
		}
		cout << '\n';
	}
}

int main()
{
	int m, n, cs = 0;
	while (cin >> n >> m, n || m)
	{
		G.clear();
		W.clear();
		unordered_map<string, int> M;
		W.resize(n);
		G.resize(n);
		string a, b;
		int k = 0;
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
		}
		if (cs != 0) cout << '\n';
		cout << "Calling circles for data set " <<  ++cs << ":\n";
		num.assign(k, -1); low.assign(k, 0); discovery.assign(k, 0);
		cnt = SCC = 0; 
		for (int i = 0; i < k; ++i)
			if (num[i] == -1)
				tarjan(i);
	}
}
