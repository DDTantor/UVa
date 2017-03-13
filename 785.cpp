#include <iostream>
#include <string>
#include <vector>
#include <istream>

using namespace std;

char wall;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
vector<string> S;


void dfs(int y, int x, char p)
{
    if (x >= 0 && y >= 0 && y < S.size() && x < S[y].size() && S[y][x] == ' ')
    {
        S[y][x] = p;
        for (int i = 0; i < 4; ++i)
            dfs(y + dy[i], x + dx[i], p);
    }
}

int main()
{
    while(cin.peek() != EOF)
    {
        int n = 0;
        string s;
        while(getline(cin, s), s[0] != '_')
            S.push_back(s);
        
        wall = ' ';
        for (int i = 0; i < S.size() && wall == ' '; ++i)
            for (int j = 0; j < S[i].size() && wall == ' '; ++j)
                if(S[i][j] != ' ')
                    wall = S[i][j];
        
        for (int i = 0; i < S.size(); ++i)
        {
            for (int j = 0; j < S[i].size(); ++j)
            {
                if (S[i][j] != wall && S[i][j] != ' ')
                {
                    char p = S[i][j];
                    S[i][j] = ' ';
                    dfs(i, j, p);
                }
            }
        }
                    
        for (int i = 0; i < S.size(); ++i)
            cout << S[i] << '\n';
        
        cout << s << '\n';
        S.clear();
    }
}
