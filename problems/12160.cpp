#include <iostream>
#include <vector>
#include <tuple>
#include <iomanip>
#include <queue>
#include <cstring>

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int mod = 10000;

int U, L, R, V[10000], cs = 1;
vi nums;

string bfs()
{
    queue<ii> Q;
    Q.emplace(0, L);
    while (!Q.empty())
    {
        int d, u;
        tie(d, u) = Q.front(); Q.pop();
        if (u == U)
            return to_string(d);

        for (int x : nums)
        {
            int v = (u + x) % mod;
            if (!V[v])
                Q.emplace(d + 1, v), V[v] = 1;
        }
    }

    return "Permanently Locked";
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> L >> U >> R, L + U + R)
    {
        memset(V, 0, sizeof V);
        nums.assign(R, 0);
        for (int i = 0; i < R; ++i)
            cin >> nums[i];
        
        cout << "Case " << cs++ << ": " << bfs() << '\n';
    }
}
