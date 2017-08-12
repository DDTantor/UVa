#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t, m, n, x, y;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};
    string S = "NESW", L[60];
    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        cin.ignore();
        cin.ignore();
        for (int i = 0; i < m; ++i)
            getline(cin, L[i]);
        
        unsigned dir = 0;
        cin >> y >> x;
        char c;
        y--, x--;
        while (cin >> c, c != 'Q')
        {
            int xx = x, yy = y;
            if (c == 'F')
                xx += dx[dir], yy += dy[dir];
            else
                dir = (dir + (c == 'R'? 1 : -1)) % 4;
            if (L[yy][xx] != '*')
                x = xx, y = yy;
        }
        cout << y + 1 << ' ' << x + 1 << ' ' << S[dir] << '\n';
        if (t)
            cout << '\n';
    }
    
}
