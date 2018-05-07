#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

typedef tuple<int, string> state;

string E = "123456789", S;

unordered_map<string, string> P;
unordered_map<string, int> V;

string Hor(string st, int i)
{
    swap(st[3 * i], st[3 * i + 2]);
    swap(st[3 * i], st[3 * i + 1]);
    return st;
}

string Vert(string st, int i)
{
    swap(st[i], st[i + 3]);
    swap(st[i], st[i + 6]);
    return st;
}

void bfs()
{
    queue<state> Q;
    Q.emplace(0, E);
    P[E] = "";
    while (!Q.empty())
    {
        string st;
        int dist;
        tie(dist, st) = Q.front(); Q.pop();
        
        for (int k = 0; k < 2; ++k)
        {
            for (int i = 0; i < 3; ++i)
            {
                string cst = (k ? Vert(st, i) : Hor(st, i));
                string mv(2, ' ');
                mv[0] = (k ? 'V' : 'H');
                mv[1] = '1' + i;
                auto it = P.emplace(cst, mv + P[st]);
                if (it.second)
                    V.emplace(cst, dist + 1), Q.emplace(dist + 1, cst); 
            }
        }
    }
}

int main()
{
    bfs();
    while (cin.peek() != '0')
    {
        S = string(9, ' ');
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cin >> S[i * 3 + j];

        if (P[S] != "")
        {
            cout << V[S] << ' ' << P[S];
            cout << '\n';
        }
        else if (S == E)
            cout << "0\n";
        else
            cout << "Not solvable\n";
        
        cin.ignore();
    }
}
