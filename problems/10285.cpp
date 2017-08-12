#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <stack>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int t, r, c, A[100][100];

stack<ii> S;

void dfs(bool V[100][100], int y, int x)
{
    V[y][x] = true;
    for (int i = 0; i < 4; ++i)
    {
        int xx = x + dx[i], yy = y + dy[i];
        if (xx >= 0 && xx < c && yy >= 0 && yy < r && A[y][x] > A[yy][xx] && !V[yy][xx])
            dfs(V, yy, xx);
    }
    S.emplace(y, x);
}

int rlx(int y, int x, int yy, int xx, int D[100][100])
{
    if (D[y][x] + 1 > D[yy][xx])
        D[yy][xx] = D[y][x] + 1;
    return D[yy][xx];
}

int main()
{
    string  s;
    cin >> t;
    while (cin >> s >> r >> c, t--)
    {
        cout << s << ": ";
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> A[i][j];
                
        vvi G(r * c);
        bool V[100][100] = {};
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                dfs(V, i, j);
        
        int D[100][100] = {}, m = 0, x, y;
        while (!S.empty())
        {
            tie(y, x) = S.top(); S.pop();
            for (int i = 0; i < 4; ++i)
            {
                int yy = y + dy[i], xx = x + dx[i];
                if (xx >= 0 && yy >= 0 && xx < c && yy < r && A[y][x] > A[yy][xx])
                    m = max(m, rlx(y, x, yy, xx, D));
            }
        }
        cout << m + 1 << '\n';
    }
}
