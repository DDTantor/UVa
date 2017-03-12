#include <iostream>
#include <queue>
#include <utility>
#include <tuple>


using namespace std;

typedef pair<int, int> ii;

int n, c = 1;
string A[200];

int dx[6] = {0, 1, 0, -1, -1, 1};
int dy[6] = {-1, 0, 1, 0, -1, 1};

bool won;

void BW(int y, int x)
{
    if (y == n)
        won = true;
    if (x >= 0 && y >= 0 && y < n && x < n && A[y][x] == 'b')
    {
        A[y][x] = 'w';
        for (int i = 0; i < 6; ++i)
            BW(y + dy[i], x + dx[i]);
    }
}

int main()
{
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        won = false;
        for (int i = 0; i < n; ++i)
            if (A[0][i] == 'b')
                BW(0, i);    
                
        cout << c++ << ' ';
        if(won)
            cout << "B\n";
        else
            cout << "W\n";
    }
}
