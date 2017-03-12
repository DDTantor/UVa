#include <iostream>
#include <string>

using namespace std;

int main()
{
    int r, c, s;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    string S = "NESW";
    while (cin >> r >> c >> s, r && c && s)
    {
        string l[10];
        int b[10][10] = {};
        int y = 0, x = s - 1, dir, cnt = 0;
        for (int i = 0; i < r; ++i)
            cin >> l[i];
            
        bool out = false;
        b[x][y] = 0;
        while(!out)
        {
            cnt++;
            dir = S.find(l[y][x]);
            x += dx[dir];
            y += dy[dir];
            if (x >= c || y >= r || x < 0 || y < 0)
                out = true;
            else if (b[x][y] || (!b[x][y] && x == s - 1 && y == 0))
                break;
        
            b[x][y] = cnt;
        }
        
        if (out)
            cout << cnt << " step(s) to exit\n";
        else
            cout << b[x][y] << " step(s) before a loop of " << cnt - b[x][y] << " step(s)\n";
    }
    
}
