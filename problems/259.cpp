#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

#define inf 1e9

typedef vector<int> vi;
typedef vector<vi> vvi;

int R[38][38];
vvi G;
vi P;

bool ap()
{
    int k;
    queue<int> Q;
    Q.push(0);
    P.assign(38, -1);
    while (!Q.empty())
    {
        k = Q.front(); Q.pop();
        if (k == 37)
            return true;

        for (int x = 0; x < 38; ++x)
            if (P[x] == -1 && R[k][x] > 0)
                P[x] = k, Q.push(x);
    }
    return false;
}

int main()
{
    while (!cin.eof())
    {
        G.assign(38, vi());
        memset(R, 0, sizeof(R));
        string s;
        int sum = 0;
        while (getline(cin, s), !s.empty())
        {
            istringstream iss(s);
            char c, p;
            int x, u, v;
            iss >> c >> x;
            sum += x;
            u = c - 'A' + 1;
            R[0][u] = R[u][0] = x;
            while (iss >> p, p != ';')
                v = p - '0' + 27, R[u][v] = inf;
        }
        for (int i = 27; i < 37; ++i)
            G[i].push_back(37), R[i][37] = R[37][i] = 1;

        
        int f = 0;
        while (ap())
        {
            for (int x = 37; x != 0; x = P[x])
                R[P[x]][x]--, R[x][P[x]]++;
            f++;
        }
        if (f != sum)
            cout << "!\n";
        else
        {
            for (int i = 27; i < 37; ++i)
            {
                char c = '_';
                for (int j = 1; j < 27; ++j)
                    if (R[i][j] == 1)
                        c = j + 'A' - 1;
                cout << c;
            }
            cout << '\n';
        } 
    }
          
}
