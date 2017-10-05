#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

typedef vector<int> vi;

int X, Y, p, m, R[2 * 30 * 30 + 2][2 * 30 * 30 + 2];
vi P;
string S[30];

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
const int s = 2 * 30 * 30;
const int t = 2 * 30 * 30 + 1;

bool good(int y, int x)
{
    return y >= 0 && x >= 0 && y < X && x < Y && S[y][x] != '~' && S[y][x] != '*';
}

bool ap()
{
    queue<int> Q;
    P.assign(2 * 30 * 30 + 2, -1);
    Q.push(s);
    while (!Q.empty())
    {
        int k = Q.front(); Q.pop();
        if (k == t)
            return true;

        for (int x = 0; x < 2 * 30 * 30 + 2; ++x)
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }

    return false;

}

int main()
{
    while (cin >> X >> Y >> p)
    {
        memset(R, 0, sizeof(R));
        for (int i = 0; i < X; ++i)
            cin >> S[i];

        for (int i = 0; i < X; ++i)
        {
            for (int j = 0; j < Y; ++j)
            {
                if (S[i][j] == '*')
                {
                    R[s][30 * i + j] = 1;
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k]; 
                        if (good(ky, kx))
                            R[30 * i + j][30 * ky + kx] = 1; 
                    }
                }
                else if (S[i][j] == '@')
                {
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (good(ky, kx))
                            R[30 * i + j][30 * ky + kx] = 1000;
                    }
                }
                else if (S[i][j] == '#')
                {
                    R[30 * i + j][t] = p;
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (good(ky, kx))
                            R[30 * i + j][30 * ky + kx] = 1000;
                    }
                }
                else if (S[i][j] == '.')
                {
                    R[30 * i + j][30 * i + j + 30 * 30] = 1;
                    for (int k = 0; k < 4; ++k)
                    {
                        int ky = i + dy[k], kx = j + dx[k];
                        if (good(ky, kx))
                            R[30 * i + j + 30 * 30][30 * ky + kx] = 1;
                    }
                }
            }
        }
        
        m = 0;
        while (ap())
        {
            int aug = 1000;
            for (int x = t; x != s; x = P[x])
                aug = min(aug, R[P[x]][x]);
            
            for (int x = t; x != s; x = P[x])
                R[P[x]][x] -= aug, R[x][P[x]] += aug;

            m += aug;
        }
        cout << m << '\n';
    }
}
