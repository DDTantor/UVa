#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

int main()
{
    int n, m, r;
    while (cin >> m >> n)
    {
        vvii M(n);
        for (int i = 0; i < m; ++i)
        {
            cin >> r;
            vi Pos(r), Num(r);
            for (int j = 0; j < r; ++j)
                cin >> Pos[j];
            for (int j = 0; j < r; ++j)
                cin >> Num[j];
            for (int j = 0; j < r; ++j)
                M[Pos[j] - 1].emplace_back(i, Num[j]);
        }
        cout << n << ' ' << m << '\n';
        for (int i = 0; i < n; ++i)
        {
            cout << M[i].size();
            for (auto e : M[i])
                cout << ' ' << (e).first + 1;
            cout << '\n';
            for (int j = 0; j < M[i].size(); ++j)
            {
                if (j)
                    cout << ' ';
                cout << M[i][j].second;
            }
            cout << '\n';
        }
    }
}
