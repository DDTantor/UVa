#include <iostream>
#include <set>
#include <tuple>
#include <utility>
#include <functional>

using namespace std;

typedef pair <int, char> ic;

int m, n;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void fill(int y, int x, string S[100], char c) 
{
    if (x >= 0 && y >= 0 && x < n && y < m && S[y][x] == c)
    {
        S[y][x] = '0';
        for (int i = 0; i < 4; ++i)
            fill(y + dy[i], x + dx[i], S, c);
    }
}

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        string S[100];
        auto cmp = [](ic a, ic b)->bool{return (a.first > b.first || (a.first == b.first && a.second < b.second));};
        set<ic, decltype(cmp)> res (cmp);
        for (int i = 0; i < m; ++i)
            cin >> S[i];
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if(S[i][j] != '0')
                {
                    char c = S[i][j];
                    int cnt = 0;
                    for (int k = 0; k < m; ++k)
                        for (int l = 0; l < n; ++l)
                            if (S[k][l] == c)
                                cnt++, fill(k, l, S, c);
                    
                    res.insert(ic(cnt, c));
                }
            }
        }
        cout << "World #" << c++ << '\n';
        for (auto e : res)
            cout << e.second << ": " << e.first << '\n'; 
    }
    
}
