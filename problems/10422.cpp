#include <iostream>
#include <queue>
#include <cstring>
#include <tuple>
#include <set>
#include <algorithm>

using namespace std;

typedef vector<string> vs;
typedef pair<int, int> ii;
typedef tuple<vs, int, int, int> pos;

int dx[8] = {-1, -1, 1, 1, -2, -2, 2, 2};
int dy[8] = {-2, 2, 2, -2, 1, -1, 1, -1};

vs res =
{
    "11111",
    "01111",
    "00 11",
    "00001",
    "00000"
};

int bfs(vs& board, int x, int y)
{
    set<pos> known;
    queue<pos> Q;
    Q.emplace(board, x, y, 0);
    while (!Q.empty())
    {
        int x1, y1, c;
        vs curr;
        tie(curr, x, y, c) = Q.front(); Q.pop();
        if (c == 11)
            continue;
        if (curr == res)
            return c;
            
        for (int i = 0; i < 8; ++i)
        {
            x1 = x + dx[i];
            y1 = y + dy[i];
            if (x1 >= 0 && y1 >= 0 && x1 < 5 && y1 < 5)
            {
                vs next = curr;
                swap(next[y][x], next[y1][x1]);
                pos nepos = make_tuple(next, x1, y1, c + 1);
                if (known.find(nepos) == known.end())
                {
                    Q.push(nepos);
                    known.insert(nepos);
                }
            }
        }
    }
    return 11;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        vs board(5);
        for (int i = 0; i < 5; ++i)
            getline(cin, board[i]);

        int x, y;
        for (int i = 0; i < 5; ++i)
            for (int j = 0; j < 5; ++j)
                if (board[i][j] == ' ')
                    x = j, y = i;

        int c = bfs(board, x, y);
        if (c >= 11)
            cout << "Unsolvable in less than 11 move(s).\n";
        else
            cout << "Solvable in " << c << " move(s).\n";
    }
}
