#include <iostream>
#include <numeric>
#include <vector>
#include <sstream>

using namespace std;

typedef vector<int> vi;

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
    
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
    
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;
        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }
    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        cin.ignore();
        UF C(n);
        string s;
        char c;
        int u, v;
        int cnt1 = 0, cnt2 = 0;
        while (getline(cin, s), !s.empty())
        {
            istringstream iss(s);
            iss >> c >> u >> v;
            u--, v--;
            if (c == 'c')
                C.u(u, v);
            else if (C.s(u, v))
                cnt1++;
            else
                cnt2++;
        }
        cout << cnt1 << ',' << cnt2 << '\n';
        if (t)
            cout << '\n';
    }
}
