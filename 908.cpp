#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>

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
};

int main()
{
    int a, b, n, k, m, w;
    while (cin >> n)
    {
        int cnt = 0;
        viii E;
        for (int i = 0; i < n - 1; ++i)
            cin >> w >> w >> w, cnt += w;
        
        cout << cnt << '\n';
        for (int j = 0; j < 2; ++j)
        {
            cin >> k;
            for (int i = 0; i < k; ++i)
                cin >> a >> b >> w, E.emplace_back(w, a - 1, b - 1);
        }
        cnt = 0;
        sort(E.begin(), E.end());
        UF uf(n);
        for (auto t : E)
        {
            tie(w, a, b) = t;
            if (!uf.s(a, b))
                cnt += w, uf.u(a, b);
        }
        cout << cnt << '\n';
        cin.ignore();
        if (cin.peek() != EOF)
            cout << '\n';
    }
}

