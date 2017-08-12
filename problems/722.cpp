#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int cnt, r, c;

void dfs(int y, int x, string S[100])
{
    if (x >= 0 && y >= 0 && x < c && y < r && S[y][x] == '0')
    {
        cnt++;
        S[y][x] = '1';
        for (int i = 0; i < 4; ++i)
            dfs(y + dy[i], x + dx[i], S);
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        string s;
        int x, y;
        getline(cin, s);
        istringstream iss(s);
        string S[100];
        iss >> y >> x;
        y--, x--;
        int n = 0;
        while (getline(cin, s), !s.empty())
            S[n++] = s;
        
        r = n;
        c = S[0].size();
        cnt = 0;
        dfs(y, x, S);
        cout << cnt << '\n';
        if (t)
            cout << '\n';
    }
}
