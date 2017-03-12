#include <iostream>
#include <string>

using namespace std;

int r, c;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int y, int x, string S[100])
{
    if (y >= 0 && x >= 0 && y < r && x < c && S[y][x] == ' ')
    {
        S[y][x] = '#';
        for (int i = 0; i < 4; ++i)
            dfs(y + dy[i], x + dx[i], S);
    } 
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        int n = 0;
        string s;
        string S[100];
        while (getline(cin, s), s[0] != '_')
            S[n++] = s;
        
        r = n, c = S[0].size();
        int x = -1, y = -1;
        for (int i = 0; i < r && x < 0 && y < 0; ++i)
            for (int j = 0; j < c && x < 0 && y < 0; ++j)
                if (S[i][j] == '*')
                    y = i, x = j;
        
        S[y][x] = ' ';
        dfs(y, x, S);
        for (int i = 0; i < r; ++i)
            cout << S[i] << '\n';
        cout << s << '\n';
    }
}
