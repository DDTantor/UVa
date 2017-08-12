#include <iostream>

using namespace std;

int cnt, n, m;
char A[100][100];
int M[2][8] = {{-1,0,1,-1,1,-1,0,1},
               {-1,-1,-1,0,0,1,1,1}};
void Color(int i, int j)
{
    if (i >= 0 && j >= 0 && i < n && j < m && A[i][j] == '@')
    {
        A[i][j] = '*';
        for (int k = 0; k < 8; ++k)
            Color(i + M[0][k], j + M[1][k]);
    }
}

int main()
{
    while (cin >> n >> m, n || m)
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> A[i][j];
                
        cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (A[i][j] == '@')
                {
                    cnt++;
                    Color(i, j);
                }
        cout << cnt << '\n';
    }   
}
