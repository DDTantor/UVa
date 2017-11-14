#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector<vc> vvc;

string S[10][5] =
{
    {" - ",
     "| |",
     "   ",
     "| |",
     " - "},
    {"   ",
     "  |",
     "   ",
     "  |",
     "   "},
    {" - ",
     "  |",
     " - ",
     "|  ",
     " - "},
    {" - ",
     "  |",
     " - ",
     "  |",
     " - "},
    {"   ",
     "| |",
     " - ",
     "  |",
     "   "},
    {" - ",
     "|  ",
     " - ",
     "  |",
     " - "},
    {" - ",
     "|  ",
     " - ",
     "| |",
     " - "},
    {" - ",
     "  |",
     "   ",
     "  |",
     "   "},
    {" - ",
     "| |",
     " - ",
     "| |",
     " - "},
    {" - ",
     "| |",
     " - ",
     "  |",
     " - "}
}, s;

void put(int a, vvc& res, int n)
{
    int j = 0;
    for (int i = 0; i < 3; ++i, ++j)
    {
        res[i + i * n].push_back(' ');
        for (int l = 1; l <= n; ++l)
            res[i + i * n].push_back(S[a][j][1]);

        res[i + i * n].push_back(' ');
        
        ++j;
        if (i == 2)
            break;
        
        for (int l = 0; l < n; ++l)
        {
            res[i + 1 + n * i + l].push_back(S[a][j][0]);
            for (int k = 1; k <= n; ++k)
                res[i + 1 + n * i + l].push_back(S[a][j][1]);

            res[i + 1 + n * i + l].push_back(S[a][j][2]);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n >> s, n)
    {
        vvc res(3 + 2 * n, vc());
        for (int i = 0; i < s.size(); ++i)
        {
            put(s[i] - '0', res, n);
            if (i != s.size() - 1)
                for (auto& v : res)
                    v.push_back(' ');
        }

        for (auto v : res)
        {
            for (char c : v)
                cout << c;

            cout << '\n';
        }

        cout << '\n';
    }
}
