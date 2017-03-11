#include <iostream>
#include <string>

using namespace std;
    
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string S = "NESW";
int X, Y, x, y;
char dir;
string s;
bool Scent[52][52] = {};

int main()
{ 
    cin >> X >> Y;
    while (cin >> x >> y >> dir)
    {
        cin >> s;
        bool out = false;
        unsigned turn = S.find(dir);
        for (int i = 0; i < s.size() && !out; ++i)
        {
            int xx = x, yy = y;
            if (s[i] == 'F')
                    xx += dx[turn], yy += dy[turn];
            else
                turn = (turn + (s[i] == 'R'? 1 : -1)) % 4;
            
            if (xx < 0 || yy < 0 || xx > X || yy > Y)
            {   
                if (!Scent[x][y])
                    out = true;
                Scent[x][y] = true;
            }
            else
                x = xx, y = yy;
        }
        cout << x << ' ' << y << ' ' << S[turn];
        if (out)
            cout << " LOST";
        cout << '\n';
    }
}
