#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point () {}
    friend istream& operator >>(istream& in, point& p)
    {
        return in >> p.x >> p.y;
    }
    double dist(point p)
    {
        return hypot(x - p.x, y - p.y);
    }
} G, D, P[1000];

int n;
void solve()
{
    for (int i = 0; i < n; ++i)
    {
        if (2 * P[i].dist(G) < P[i].dist(D) + eps)
        {
            cout << fixed << setprecision(3) << "The gopher can escape through the hole at (" << P[i].x << ',' << P[i].y << ").\n";
            return;
        }
    }

    cout << "The gopher cannot escape.\n";
}

int main()
{
    while (cin >> n)
    {
        cin >> G >> D;
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        solve();
    }
}
