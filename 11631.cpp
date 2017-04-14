#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<iii> viii;

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
    int m, n;
    while (cin >> m >> n, m || n)
    {
        UF uf(m);
        viii E;
        int u, v, w, sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> u >> v >> w;
            E.emplace_back(w, u, v);
            E.emplace_back(w, v, u);
            sum += w;
        }
        sort(E.begin(), E.end());
        for (auto t : E)
        {
            tie(w, u, v) = t;
            if (!uf.s(u, v))
                sum -= w, uf.u(u, v);
        }
        cout << sum << '\n';
    }
}
