#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct UF
{
    int m = 1;
    vi r, p, size;
    UF(int n) : r(n), p(n), size(n, 1)
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
            size[x] += size[y];
            if (r[x] == r[y])
                r[x]++;
        }
        else
        {
            p[x] = y;
            size[y] += size[x];
        }
        m = max(m, max(size[y], size[x]));
    }
    
    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int a, b, t, m, n;
    cin >> t;
    while (cin >> m >> n, t--)
    {
        UF uf(m);
        for (int i = 0; i < n; ++i)
            cin >> a >> b, uf.u(a - 1, b - 1);
        cout << uf.m << '\n';
    }
}
