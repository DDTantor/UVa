#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct UF
{
    vi r, p, mon;
    UF(int n) : r(n), p(n), mon(n)
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
            mon[x] += mon[y];
            if (r[x] == r[y])
                r[x]++;
        }
        else
        {
            p[x] = y;
            mon[y] += mon[x];
        }
    }
    
    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int m, n, t;
    cin >> t;
    while (cin >> m >> n, t--)
    {
        int a, b;
        UF uf(m);
        for (int i = 0; i < m; ++i)
            cin >> uf.mon[i];
            
        for (int i = 0; i < n; ++i)
            cin >> a >> b, uf.u(a, b);
        
        bool flag = true;
        for (int i = 0; i < m; ++i)
            flag &= (uf.mon[uf.f(i)] == 0);
            
        cout << (flag? "POSSIBLE\n" : "IMPOSSIBLE\n");
    }
}
