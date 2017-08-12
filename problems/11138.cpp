#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

vi V;
vvi G;

int Aug(vi& M, int u)
{
	if (V[u])
		return 0;
		
	V[u] = true;
	for (int v : G[u])
	{
		if (M[v] == -1 || Aug(M, M[v]))
		{
			M[v] = u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int m, n, t, flag, cs = 1;
	cin >> t;
	while (cin >> m >> n, t--)
	{
		G.clear();
		G.resize(n + m);
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> flag;
				if (flag)
					G[i].push_back(j + m);
			}
		}
		int MCBM = 0;
		vi M(n + m, -1);
		for (int i = 0; i < n + m; ++i)
		{
			V.assign(n + m, 0);
			MCBM += Aug(M, i);
		}
		cout << "Case " << cs++ << ": a maximum of " << MCBM  << " nuts and bolts can be fitted together\n";
	}
	
}
