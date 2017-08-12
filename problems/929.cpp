#include <iostream>
#include <climits>
#include <cstring>
#include <queue>
#include <tuple>
#include <functional>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<iii> viii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dx[4] = {-1,  0, 1,  0};
const int dy[4] = { 0 , 1, 0, -1};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, A[1000][1000];
        cin >> m >> n;
        vvi D(m, vi(n, 10 * n * m));
        
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];
                
        D[0][0] = A[0][0];
        priority_queue<iii, viii, greater<iii> > PQ;
        PQ.emplace(D[0][0], 0, 0);
        while (!PQ.empty())
        {
            int x, y, d;
            tie(d, x, y) = PQ.top(); PQ.pop();
            if (x == n - 1 && y == m - 1)
                break;
            if (D[y][x] < d)
                continue;
                
            for (int i = 0; i < 4; ++i)
            {
                int xx = dx[i] + x, yy = dy[i] + y;
                if (xx >= 0 && yy >= 0 && xx < n && yy < m && A[yy][xx] + D[y][x] < D[yy][xx]) 
                    D[yy][xx] = D[y][x] + A[yy][xx], PQ.emplace(D[yy][xx], xx, yy);
            }
        }
        cout << D[m - 1][n - 1] << '\n';
    }
    
}
