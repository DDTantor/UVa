#include <iostream>

using namespace std;

bool Over(char G[1000][3][3], int cnt)
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (G[cnt][i][j] == '1')
                return false;
    
    return true;
}

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        char G[1000][3][3];
        
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> G[0][i][j];
            
        int cnt = 0;
        while (!Over(G, cnt))
        {
            for (int y = 0; y < 3; ++y)
            {
                for (int x = 0; x < 3; ++x)
                {
                    int cell = 0;
                    for (int k = 0; k < 4; ++k)
                    {
                        int xx = x + dx[k], yy = y + dy[k];
                        if (xx >= 0 && yy >= 0 && xx < 3 && yy < 3)
                            cell += (G[cnt][yy][xx] == '1');
                    }
                    G[cnt + 1][y][x] = '0' + (cell % 2);
                }
            }
            cnt++;
        }
        cout << cnt - 1 << '\n';
        
    }
        
}
    

