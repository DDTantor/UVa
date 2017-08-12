#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <tuple>
#include <iomanip>
#include <cmath>

using namespace std;

typedef tuple<double, double, double> ddd;
typedef pair<double, double> dd;
typedef vector<dd> vdd;
typedef vector<int> vi;
typedef vector<ddd> vddd;

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

double dist(dd a, dd b)
{
    return hypot(a.first - b.first, a.second - b.second);
}

int main()
{
    int n, t;
    cin >> t;
    while (cin >> n, t--)
    {
        vdd P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i].first >> P[i].second;
            
        vddd E;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                E.emplace_back(dist(P[i], P[j]), i, j);
        
        sort(E.begin(), E.end());
        double sum = 0, w;
        int a, b;
        UF uf(n);
        for (auto t : E)
        {
            tie(w, a, b) = t;
            if (!uf.s(a, b))
                sum += w, uf.u(a, b);
        }
        cout << fixed << setprecision(2) << sum << '\n';
        if (t)
            cout << '\n';
    }
}
