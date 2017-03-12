#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    int row, col, step, x, y;
    unsigned dir;
    string S = "NLSO", A;
    char L[100][100];
    while (cin >> row >> col >> step, row || col || step)
    {
        char L[100][100];
        for (int i = 0; i < row; ++i)
        {
            for (int j = 0; j < col; ++j)
            {
                cin >> L[i][j];
                if (isalpha(L[i][j]))
                    y = i, x = j, dir = S.find(L[i][j]);
            }
        }
        
        cin >> A;
        int cnt = 0;
        for (char c : A)
        {
            int xx = x, yy = y;
            if (c == 'F')
                xx += dx[dir], yy += dy[dir];
            else
                dir = (dir + (c == 'D'? 1 : -1)) % 4;
            
            if (xx < col && yy < row && xx >= 0 && yy >= 0)
            {
                if (L[yy][xx] != '#') 
                    x = xx, y = yy;
                
                if (L[y][x] == '*')
                    cnt++, L[y][x] = '.';
                
            }
        }
        cout << cnt << '\n';
    } 
}
