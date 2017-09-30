#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <tuple>

using namespace std;

typedef vector<int> vi;
typedef tuple<int, int, int> iii;
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

    void cl(int n)
    {
        r.assign(n, 0), p.assign(n, 0), iota(p.begin(), p.end(), 0); 
    }
};

int t, n, m, a, b, w, sum, cnt, tmp;
viii E, sol;

int main()
{
    cin >> t;
    while (cin >> n >> m, t--)
    {
        E.clear();
        sol.clear();
        for (int i = 0; i < m; ++i)
            cin >> a >> b >> w, E.emplace_back(w, --a, --b);

        sort(E.begin(), E.end());
        sum = 0;
        UF uf(n);
        for (int i = 0; i < E.size(); ++i)
        {
            tie(w, a, b) = E[i];
            if (!uf.s(a, b))
                sum += w, uf.u(a, b), sol.push_back(E[i]);
        }
        cout << sum << ' ';
        sum = 100 * 300;
        for (int i = 0; i < sol.size(); ++i)
        {
            tmp = 0;
            cnt = 0;
            uf.cl(n);
            for (int j = 0; j < E.size(); ++j)
            {
                tie(w, a, b) = E[j];
                if (E[j] != sol[i] && !uf.s(a, b))
                    tmp += w, uf.u(a, b), cnt++;
            }
            if (cnt == n - 1)
                sum = min(sum, tmp);
        }
        cout << sum << '\n';
    }
}
