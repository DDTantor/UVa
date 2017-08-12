#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (point& b) {return x < b.x || (x == b.x && y < b.y);}
};

double cross(point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    sort(P.begin(), P.end());
    vector<point> H(2 * n);
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    H.resize(k - 1);
    return H;
}

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        vector<point> P;
        for (int i = 0; i < n; ++i)
        {
            int x, y;
            char c;
            cin >> x >> y >> c;
            if (c == 'Y')
                P.emplace_back(x, y);
        }
        P = ConvexHull(P);
        cout << P.size() << '\n';
        for (int i = 0; i < P.size(); ++i)
            cout << fixed << setprecision(0) << P[i].x << ' ' << P[i].y << '\n';
    }
}
