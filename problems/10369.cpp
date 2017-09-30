#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef tuple<double, int, int> dii;
typedef vector<dii> vdii;

struct point
{
    double x, y;
    point(double x, double y) : x(x), y(y) {}
    point(){}
    friend istream& operator >>(istream& in, point& p){return in >> p.x >> p.y;}
};

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

point P[500];
vdii E;
int t, s, p, a, b;

double dist(point& a, point& b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

int main()
{
    cin >> t;
    while (cin >> s >> p, t--)
    {
        E.clear();
        for (int i = 0; i < p; ++i)
            cin >> P[i];
        
        for (int i = 0; i < p; ++i)
            for (int j = i + 1; j < p; ++j)
                E.emplace_back(dist(P[i], P[j]), i, j);
            
        
        sort(E.begin(), E.end());
        double sum = 0, w;
        UF uf(p);
        for (int i = 0; i < E.size() && s < p; ++i)
        {
            tie(w, a, b) = E[i];
            if (!uf.s(a, b))
                sum = max(sum, w), uf.u(a, b), s++;
        }
        cout << fixed << setprecision(2) << sum << '\n';
    }
}

