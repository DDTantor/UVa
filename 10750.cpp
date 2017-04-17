#include <iostream>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <climits>
#include <vector>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (const point& b) const { return y < b.y;} 
};

bool cmpx(point& a, point& b) { return a.x < b.x;}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        set<point> box;
        cin >> n;
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i].x >> P[i].y;
        sort(P.begin(), P.end(), cmpx);
        double best = INT_MAX;
        double bestx, besty;
        box.insert(P[0]);
        int left = 0;
        for (int i = 1; i < n; ++i)
        {
            while (left < i && P[i].x - P[left].x > best)
                box.erase(P[left++]);
            point B(P[i].x - best, P[i].y - best);
            for (auto it = box.lower_bound(B); it != box.end() && P[i].y + best >= it->y; ++it)
            {
                double dis = hypot(P[i].y - it->y, P[i].x - it->x);
                if (best > dis)
                    best = dis, bestx = 0.5 * (P[i].x + it->x), besty = 0.5 * (P[i].y + it->y);
            }
            box.insert(P[i]);
        }
        cout << fixed << setprecision(4) << bestx << ' ' << besty << '\n';
    }
}
