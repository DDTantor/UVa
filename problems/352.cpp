#include <iostream>
#include <string>

using namespace std;

int n, c = 1;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
string A[25];

void dfs(int y, int x)
{
    if (x >= 0 && y >= 0 && x < n && y < n && A[y][x] == '1')
    {
        A[y][x] = '0';
        for (int i = 0; i < 8; ++i)
            dfs(y + dy[i], x + dx[i]);
    }
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (A[i][j] == '1')
                    cnt++, dfs(i, j);
        
        cout << "Image number " << c++ << " contains " << cnt << " war eagles.\n";
    }
}
