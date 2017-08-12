#include <iostream>
#include <cstdio>
#include <iomanip>

using namespace std;

#define MAX 1000000

int main()
{
	int k, cs = 1, D[20][20], u, v;
	while (cin.peek() != EOF)
	{
		cout << "Test Set #" << cs++ << '\n';
		for (int i = 0; i < 20; ++i)
			for (int j = 0; j < 20; ++j)
				D[i][j] = (i == j ? 0 : MAX);
				
		for (int u = 0; u < 19; ++u)
		{
			cin >> k;
			for (int i = 0; i < k; ++i)
			{
				cin >> v;
				D[u][v - 1] = D[v - 1][u] = 1;
			}
		}
		
		for (int k = 0; k < 20; ++k)
			for (int i = 0; i < 20; ++i)
				for (int j = 0; j < 20; ++j)
					D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			
		cin >> k;
		for (int i = 0; i < k; ++i)
		{
			cin >> u >> v;
			cout << setw(2) << u << " to " << setw(2) << v << ": " << D[u - 1][v - 1] << '\n';
		}
		cin.ignore();
		cout << '\n';
	}
}
