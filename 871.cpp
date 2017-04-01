#include <iostream>

using namespace std;

int r, c, cnt;

int dfs(int y, int x, string S[100])
{
    if (x >= 0 && y >= 0 && y < r && x < c && S[y][x] == '1')
    {
        cnt++;
        S[y][x] = '0';
        for (int i = -1; i < 2; ++i)
            for (int j = -1; j < 2; ++j)
                dfs(y + i, x + j, S);
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        int n = 0;
        string s, S[100];
        while (getline(cin, s), !s.empty())
            S[n++] = s;
            
        r = n;
        c = S[0].size();
        
        
        int max = 0;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (S[i][j] == '1')
                    cnt = 0, dfs(i, j, S), max = (max < cnt? cnt : max);
        
        cout << max << '\n';
        if (t)
            cout << '\n';
    }
}
