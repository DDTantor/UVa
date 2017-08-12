#include <iostream>

using namespace std;

char p;
int m, n, cnt = 0, Y, X;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int y, int x, string S[100])
{
    if (x < 0)
        x = n - 1;
    if (x >= n)
        x = 0;
    if (y >= 0 && y < m && S[y][x] == p)
    {
        cnt++;
        S[y][x] = '0';
        for (int i = 0; i < 4; ++i)
            dfs(y + dy[i], x + dx[i], S);
    }
    
}

int main()
{
    while (cin >> m >> n)
    {
        string S[100];
        for (int i = 0; i < m; ++i)
            cin >> S[i];
        
        cin >> Y >> X;
        p = S[Y][X];
        dfs(Y, X, S);
        int max = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (S[i][j] == p)
                    cnt = 0, dfs(i, j, S), max = (max < cnt? cnt : max);
        
        cout << max << '\n';
        
    }
    
}
