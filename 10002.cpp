#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    bool operator < (const point& a) {return x < a.x || (x == a.x && y < a.y);}
    friend istream& operator >> (istream& in, point& a) {return in >> a.x >> a.y;}
};

double cross(point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    
    
    
    vector<point> H(2 * n);
    
    sort(P.begin(), P.end());
    
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

double Area(vector<point>& P)
{
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        double x1 = P[i].x, x2 = P[i + 1].x;
        double y1 = P[i].y, y2 = P[i + 1].y;
        A += (x1 * y2 - x2 * y1);
    }
    return 0.5 * fabs(A);
}

int main()
{
    int n;
    while (cin >> n, n > 2)
    {
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        
        P = ConvexHull(P);
        
        double A = Area(P);
        double X = 0, Y = 0;
        for (int i = 0; i < P.size() - 1; ++i)
        {
            double x1 = P[i].x, x2 = P[i + 1].x;
            double y1 = P[i].y, y2 = P[i + 1].y;
            X += (x1 + x2) * (x1 * y2 - x2 * y1);
            Y += (y1 + y2) * (x1 * y2 - x2 * y1);
        }
        cout << fixed << setprecision(3) << X / (6.0 * A) <<  ' ' << Y / (6.0 * A) << '\n';
    }
}
