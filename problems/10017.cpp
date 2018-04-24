#include <iostream>
#include <vector>
using namespace std;

const char C[3] = {'A', 'B', 'C'};

int n, m, cs, moves;
vector<int> S[3];

void Print()
{
    for (int k = 0; k < 3; ++k)
    {
        cout << C[k] << "=>";
        if (!S[k].empty())
            cout << "  ";
        
        for (int i : S[k])
            cout << " " << i;

        cout << '\n';
    }

    cout << '\n';
}

void solve(int count, int src, int dest, int inter)
{
    if (m < 1)
        return;
    
    if (count == 1)
    {
        S[dest].push_back(S[src].back());
        S[src].pop_back();
        Print();
        m--;
    }
    else
    {
        solve(count - 1, src, inter, dest);
        solve(1, src, dest, inter);
        solve(count - 1, inter, dest, src);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> n >> m, n + m)
    {
        cout << "Problem #" << ++cs << "\n\n";
        for (int i = 0; i < 3; ++i)
            S[i].clear();

        for (int i = 0; i < n; ++i)
            S[0].push_back(n - i);

        Print();
        solve(n, 0, 2, 1);
    }
}

