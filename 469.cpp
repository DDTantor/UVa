#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


int r, c, cnt;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void dfs(int y, int x, string S[101], bool visited[101][101])
{
    if (x >= 0 && y >= 0 && x < c && y < r && S[y][x] == 'W' && !visited[y][x])
    {
        cnt++;
        visited[y][x] = true;
        for (int i = 0; i < 8; ++i)
            dfs(y + dy[i], x + dx[i], S, visited);
    }
} 

int flood(int y, int x, string S[101])
{
    cnt = 0;
    bool visited[101][101] = {};
    dfs(y, x, S, visited);
    return cnt;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        int n = 0, x, y;
        string S[101], s;
        while (getline(cin, s), isalpha(s[0]))
            S[n++] = s;
        
        r = n;
        c = S[0].size();
        do
        {   
            cnt = 0;
            istringstream iss(s);
            iss >> y >> x;
            y--, x--;
            cout << flood(y, x, S) << '\n';
        }while (getline(cin, s), !s.empty());
        if (t)
            cout << '\n';
    }
}
