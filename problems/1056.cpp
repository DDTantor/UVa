#include <iostream>
#include <unordered_map>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

#define MAX 1000000

typedef vector<int> vi;
typedef vector<string> vs;

int main()
{
	int m, n, D[50][50], cs = 1;
	string a, b;
	
	while (cin >> n >> m, n || m)
	{
		cout << "Network " << cs++ << ": ";
		
		vs W(n);
		unordered_map<string, int> M;
		int k = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				D[i][j] = (i == j) ? 0 : MAX;
		for (int i = 0; i < m; ++i)
		{
			cin >> a >> b;
			auto p = M.emplace(a, k);
			if (p.second) W[k++] = a;
			auto q = M.emplace(b, k);
			if (q.second) W[k++] = b;
			int x = p.first->second;
			int y = q.first->second;
			D[x][y] = 1;
			D[y][x] = 1;
		}
		for (int k = 0; k < n; ++k)
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < n; ++j)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
		
		bool flag = true;
		int d = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				flag &= (D[i][j] != MAX), d = max(d, D[i][j]);
		
		if (flag)
			cout << d << "\n\n";
		else
			cout << "DISCONNECTED\n\n";
	}
}
