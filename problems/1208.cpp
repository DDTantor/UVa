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
    int t, n, cs = 1;
    cin >> t;
    while (cin >> n, t--)
    {
        cout << "Case " << cs++ << ":\n";
        viii E;
        int w;
        char c, a, b;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> w;
                if (w)
                    E.emplace_back(w, i, j);
                if (j < n - 1)
                    cin >> c;
            }
        }
        sort(E.begin(), E.end());
        UF uf(E.size());
        for (auto t : E)
        {
            tie(w, a, b) = t;
            if (!uf.s(a, b))
            {
                cout << (char)(a + 'A') << '-' << (char)(b + 'A') << ' ' << w << '\n';
                uf.u(a, b);
            }
        }
    }
}
