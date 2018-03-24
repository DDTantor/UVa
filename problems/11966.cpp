#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
#include <cmath> 

using namespace std;

#define eps 1e-6

typedef vector<int> vi;

const int maxn = 1000;

bool V[maxn];

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator>>(istream& in, point& p)
    {
        return in >> p.x >> p.y;
    }
}P[maxn];

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
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

double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

int main()
{
    int t, n;
    double d;
    cin >> t;
    for (int T = 1; T <= t; ++T)
    {
        cout << "Case " << T << ": ";
        cin >> n >> d;
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        UF uf(n);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (dist(P[i], P[j]) < d + eps)
                    uf.u(i, j);

        memset(V, false, sizeof V);
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            cnt += (!V[uf.f(i)]), V[uf.f(i)] = true;

        cout << cnt << '\n';
    }
}
