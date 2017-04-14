#include <iostream>
#include <numeric>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;

struct UF
{
    vi r, p;
    UF(int n) : r(n), p(n)
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
    int m, n, c = 1;
    while (cin >> m >> n, m || n)
    {
        UF uf(m);
        int a, b;
        for (int i = 0; i < n; ++i)
            cin >> a >> b, uf.u(a - 1, b - 1);
        
        set<int> A;
        for (int i = 0; i < m; ++i)
            A.insert(uf.f(i));
        cout << "Case " << c++ << ": " << A.size() << '\n';
    }
}
