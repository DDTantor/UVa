#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

string S[50];
int m, n, cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs2(int y, int x)
{
    if (y >= 0 && x >= 0 && y < n && x < m && S[y][x] == 'X')
    {
        S[y][x] = '*';
        for (int i = 0; i < 4; ++i)
            dfs2(y + dy[i], x + dx[i]);
    }
}

void dfs1(int y, int x)
{
    if (y >= 0 && x >= 0 && y < n && x < m && S[y][x] != '.')
    {
        if (S[y][x] == 'X')
        {
            cnt++;
            dfs2(y, x);
        }
        S[y][x] = '.';
        for (int i = 0; i < 4; ++i)
            dfs1(y + dy[i], x + dx[i]);
    }
}

int main()
{
    int c = 1;
    while (cin >> m >> n, m && n)
    {
        for (int i = 0; i < n; ++i)
            cin >> S[i];
    
        vi res;
        
        for (int y = 0; y < n; ++y)
            for (int x = 0; x < m; ++x)
                if (S[y][x] != '.')
                    cnt = 0, dfs1(y, x), res.push_back(cnt);
        
        sort(res.begin(), res.end());
        cout << "Throw " << c++ << '\n';
        for (int i = 0; i < res.size(); ++i)
        {
            if (i)
                cout << ' ';
                
            cout << res[i];
        }
        cout << "\n\n";
    }
    
}
