#include <iostream>
#include <vector>
#include <utility>
#include <functional>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int c, r, cnt, n = 1;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int y, int x, string S[100], char p)
{
    if (x >= 0 && y >= 0 && y < r && x < c && S[y][x] == p)
    {
        cnt++;
        S[y][x] = '.';
        for (int i = 0; i < 4; ++i)
            dfs(y + dy[i], x + dx[i], S, p);
    }
}

int main()
{
    while (cin >> r >> c, r || c)
    {
        string S[100];
        for (int i = 0; i < r; ++i)
            cin >> S[i];
        
        vii res;
        char p;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (S[i][j] != '.')
                    cnt = 0, p = S[i][j], dfs(i, j, S, p), res.push_back(ii(cnt, (int)-p));
                    
        sort(res.begin(), res.end(), greater<ii>());      
        cout << "Problem " << n++ << ":\n";  
        for (ii e : res)
            cout << (char)(-e.second) << ' ' << e.first << '\n';
        
    }
}
