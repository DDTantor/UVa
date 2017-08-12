#include <iostream>

using namespace std;


char A[100][100];
int B[100][100];


int main()
{
    int n, m, f = 1;
    int d[2][8] = {{-1, -1, 0, 1, 1, 1, 0, -1},
                   {0, 1, 1, 1, 0, -1 ,-1, -1}};
    while (cin >> n >> m, m || n)
    {
        if (f != 1)
            cout << '\n';
            
        cout << "Field #" << f++ << ":\n";
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j], B[i][j] = 0;
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i][j] == '*')
                    for (int k = 0; k < 8; ++k)
                        if (i + d[0][k] >= 0 && i + d[0][k] < n && j + d[1][k] >= 0 && j + d[1][k] < m)
                            B[i + d[0][k]][j + d[1][k]]++;
        
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (A[i][j] == '*')
                    cout << '*';
                else
                    cout << B[i][j];
            }
            cout << '\n';
        }
    }   
}
