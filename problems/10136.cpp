#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;

#define eps 1e-6

const double r = 2.5;

struct point
{
    double x, y;
    point (double x, double y) : x(x), y(y) {}
    point () {}
    friend istream& operator >> (istream& in, point& p) {return in >> p.x >> p.y;}
} P[200], c;

bool c2pts(point p1, point p2) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + 
                (p1.y - p2.y) * (p1.y - p2.y);
    
    double det = r * r / d2 - 0.25;
    if (det < 0.0)
        return false;
    
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}
    
bool inside(point p)
{
    return hypot(p.x - c.x, p.y - c.y) < r + eps;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        int n = 0;
        while (cin.peek() != '\n' && !cin.eof()) cin >> P[n++], cin.ignore();

        int res = 1;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                int cnt = 0;
                if (c2pts(P[i], P[j]))
                {
                    for (int k = 0; k < n; ++k)
                        cnt += inside(P[k]);

                    res = max(res, cnt);
                    cnt = 0;
                    c2pts(P[j], P[i]);
                    for (int k = 0; k < n; ++k)
                        cnt += inside(P[k]);

                }
            }
        }

        cout << res << '\n';
        if (t)
            cout << '\n';
        cin.ignore();
    }
}
