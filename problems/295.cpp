#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <numeric>

using namespace std;

#define eps 1e-6

typedef vector<int> vi;

const int maxn = 100;

int t, n, L, W;

struct point
{
    int x, y;
    point(){}
    point(int x, int y) : x(x), y(y) {}
    friend istream& operator>>(istream& in, point &p)
    {
        return in >> p.x >> p.y;
    }
} P[maxn];

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

double dist2(point p, point q)
{
    return (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
}

int main()
{
    cin >> t;
    cout << fixed << setprecision(4);
    for (int T = 1; T <= t; ++T)
    {
        cin >> L >> W >> n;
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        double lo = 0, hi = W;
        while (abs(hi - lo) > eps)
        {
            double m = 0.5 * (lo + hi);
            UF uf(n + 2);
            for (int i = 0; i < n; ++i)
            {
                if (P[i].y < m + eps)
                    uf.u(i, n);

                if(W - P[i].y < m + eps)
                    uf.u(i, n + 1);

                for (int j = i + 1; j < n; ++j)
                    if (dist2(P[i], P[j]) < m * m + eps)
                        uf.u(i, j);
            }
            
            (uf.s(n, n + 1)? hi : lo) = m;
        }
        cout << "Maximum size in test case " << T << " is " << lo << ".\n";
    }
}
