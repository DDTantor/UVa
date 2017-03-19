#include <iostream>

using namespace std;

int X, Y, cnt;

int dx[4] = {-1, -1, 1, 1};
int dy[4] = {1, -1, 1, -1};

void dfs(int x, int y, int k)
{
    if (!k)
        return;
        
    if (x - k <= X && x + k >= X && y - k <= Y && y + k >= Y)
        cnt++;
        
    for (int i = 0; i < 4; ++i)
        dfs(x + k * dx[i], y + k * dy[i] , k / 2);
}

int main()
{
    int k;
    while (cin >> k >> X >> Y, k || X || Y)
    {
        cnt = 0;
        dfs(1024, 1024, k);
        cout << "  " << cnt << '\n';
    } 
}
