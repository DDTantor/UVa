#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        int B[8][8];
        memset(B, -1, sizeof(B));
        int cnt = 0, x = s1[0] - 'a', y = s1[1] - '1';
        queue<iii> Q;
        Q.emplace(0, x, y);
        while (!Q.empty())
        {
            int l, x, y;
            tie(l, x, y) = Q.front(); Q.pop();
            if (x >= 0 && y >= 0 && x < 8 && y < 8 && B[y][x] == -1)
            {
                B[y][x] = l;
                for (int i = 0; i < 8; ++i)
                    Q.emplace(l + 1, x + dx[i], y + dy[i]);
            }
        }
        cout << "To get from " << s1 << " to " << s2 << " takes " << B[s2[1] - '1'][s2[0] - 'a'] << " knight moves.\n";
    }
}
