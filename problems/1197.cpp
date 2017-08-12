#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct UF
{
    vi r, p;
    UF(int n) : r(n + 1, 0), p(n + 1, 0)
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
    int m, n;
    while (cin >> m >> n, m || n)
    {
        UF uf(m);
        for (int i = 0; i < n; ++i)
        {
            int a, b, c;
            cin >> a >> b;
            for (int j = 0; j < a - 1; ++j)
            {
                cin >> c;
                uf.u(b, c);
            }
        }
        int cnt = 0;
        for (int i = 0; i <= m; ++i)
            cnt += uf.s(0, i);
        cout << cnt << '\n';
    }
    
}
