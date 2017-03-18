#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct point
{
    int x, y;
    point () {}
    bool operator < (const point &other) const {return x > other.x;}
    friend istream& operator >> (istream& in, point& a) {return in >> a.x >> a.y;}
}P[100];

// (y - y0)*(x1 - x0) / (y1 - y0) + x0 = x

double dist(point a, point b, point c)
{
    double y = c.y;
    double x = (double)(y - a.y) * (b.x - a.x) / (b.y - a.y) + a.x;
    return hypot(a.x - x, a.y - y);
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        double sum = 0;
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        sort(P, P + n);
        point prev = P[0];
        
        for (int i = 1; i < n; ++i)
            if (P[i].y > prev.y)
                sum += dist(P[i], P[i - 1], prev), prev = P[i];
        
        cout << fixed << setprecision(2) << sum << '\n';
    }
    
}
