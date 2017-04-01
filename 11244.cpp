#include <iostream>

using namespace std;

int m, n, cnt, s;
string S[101];
const int dx[8] = { 0,  1,  1,  1,  0, -1, -1, -1};
const int dy[8] = {-1, -1,  0,  1,  1,  1,  0, -1};


void dfs(int y, int x)
{
    if (x >= 0 && x < n && y >= 0 && y < m && S[y][x] == '*')
    {
        cnt++;
        S[y][x] = '.';
        for (int i = 0; i < 8; ++i)
            dfs(y + dy[i], x + dx[i]);
    }
}

int main()
{
    while (cin >> m >> n, m || n)
    {
        for (int i = 0; i < m; ++i)
            cin >> S[i];
            
        s = 0;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (S[i][j] == '*')
                    cnt = 0, dfs(i, j), s += (cnt == 1);
        
        cout << s << endl;
    }
    
}
