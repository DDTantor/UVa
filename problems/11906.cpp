#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in,  point& p) {return in >> p.x >> p.y;} 
    bool operator < (point& b) {return x < b.x || (x == b.x && y < b.y);}
};

double cross (point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    if (n == 1)   
        return P;
    sort(P.begin(), P.end());
    vector<point> H(2 * n);
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
        
    H.resize(k);
    return H;
}

double dist(point& a, point& b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

double Perimeter(vector<point>& P)
{
    double S = 0;
    for (int i = 0; i < P.size() - 1; ++i)
        S += dist(P[i], P[i + 1]);
        
    return S;
}

int main()
{
    int t, n;
    double l;
    cin >> t;
    while (cin >> l >> n, t--)
    {
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        P = ConvexHull(P);
        cout << fixed << setprecision(5) << max(l, Perimeter(P)) << '\n';
    }
}
