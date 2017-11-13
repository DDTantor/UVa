#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi A;
int n;

ii look(int a)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < A[i].size(); ++j)
            if (A[i][j] == a)
                return ii(i, j);

    return ii(0, 0);
}

void reset(int i, int j)
{
    A[A[i][j]].push_back(A[i][j]);
    A[i].erase(A[i].begin() + j);
}

void put(int i, int j, int k, int a)
{
    A[i].erase(A[i].begin() + j);
    A[k].push_back(a);
}

void pile(int i, int j, int k)
{
    A[k].push_back(A[i][j]);
    A[i].erase(A[i].begin() + j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    A.assign(n, vi());
    for (int i = 0; i < n; ++i)
        A[i].push_back(i);

    string comm, on;
    int a, b;
    while (cin >> comm, comm != "quit")
    {
        cin >> a >> on >> b;
        ii c = look(a), d = look(b);
        if (a == b || c.first == d.first)
            continue;

        if (comm == "move" && on == "onto")
        {
            while(d.second + 1 != A[d.first].size())
                reset(d.first, d.second + 1);

            while(c.second + 1 != A[c.first].size())
                reset(c.first, c.second + 1);

            put(c.first, c.second, d.first, a);
        }

        if (comm == "move" && on == "over")
        {
            while(c.second + 1 != A[c.first].size())
                reset(c.first, c.second + 1);

            put(c.first, c.second, d.first, a);
        }

        if (comm == "pile" && on == "onto")
        {
            while (d.second + 1 != A[d.first].size())
                reset(d.first, d.second + 1);

            while (c.second != A[c.first].size())
                pile(c.first, c.second, d.first);
        }

        if (comm == "pile" && on == "over")
            while (c.second != A[c.first].size())
                pile(c.first, c.second, d.first);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << i << ':';
        for (int j : A[i])
            cout << ' ' << j;

        cout << '\n';
    }
}
