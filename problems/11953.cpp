#include <iostream>

using namespace std;

string S[100];
int n, c = 1, t, cnt;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

void dfs(int y, int x)
{
    if (y >= 0 && y < n && x >= 0 && x < n && (S[y][x] == '@' || S[y][x] == 'x'))
    {
        S[y][x] = '.';
        for (int i = 0; i < 4; ++i)
            dfs(y + dy[i], x + dx[i]);
    }
}

int main()
{
    cin >> t;
    while (cin >> n, t--)
    {
        cout << "Case " << c++ << ": ";
        for (int i = 0; i < n; ++i)
            cin >> S[i];
            
        cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (S[i][j] == 'x')
                    cnt++, dfs(i, j);
                    
        cout << cnt << '\n';
    }
}

