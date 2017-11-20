#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

struct point
{
    int x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& p) {return in >> p.x >> p.y;}
    bool operator ==(point& p) {return x == p.x && y == p.y;}
    bool operator <(point& p) {return tie(x, y) < tie(p.x, p.y);}
} P[100];

double cross(point p, point q, point o)
{
    return (p.x - o.x) * (q.y - o.y) - (p.y - o.y) * (q.x - o.x);
}

int aligned(int i, int j, int k)
{
    return cross(P[j], P[k], P[i]) == 0;
}

int main()
{
    int t, n, cs = 0;
    double x, y;
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> x >> y, P[i] = point(round(100 * x),  round(100 * y));

        sort(P, P + n);
        n = unique(P, P + n) - P;
        cout << "Data set #" << ++cs << " contains ";
        int best = 2;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1, cnt = 2; k < n; ++k)
                    best = max(cnt += aligned(i, j, k), best);

            }
        }

        if (n == 1)
            cout << "a single gnu.\n";
        else
            cout << n << " gnus, out of which a maximum of " << best << " are aligned.\n";
    }
}
