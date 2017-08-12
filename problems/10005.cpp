#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    point() {}
    bool operator != (const point& b) const { return (x != b.x && y != b.y);}
    friend istream& operator >> (istream& in, point& a) { return in >> a.x >> a.y;}
}P[100];

bool circle2PtsRad(const point& p1, const point& p2, double r, point &c)
{
    double d2 = (p1.x - p2.x) * (p1.x - p2.x)
              + (p1.y - p2.y) * (p1.y - p2.y);
    
    double det = r * r / d2 - 0.25;
    if (det < 0.0) 
        return false;
        
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
}

double dist(const point& A, const point& B)
{
    return hypot(A.x - B.x, A.y - B.y);
}

int main()
{
    int n, k;
    double r;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        
        cin >> r;
        point c;
        bool flag = false;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i != j)
                {
                    circle2PtsRad(P[i], P[j], r, c);
                    for (k = 0; k < n; ++k)
                        if (dist(P[k], c) > r)  break;
                        
                    if (k == n)
                        flag = true;
                }
            }
        }
        if (flag)
            cout << "The polygon can be packed in the circle.\n";
        else
            cout << "There is no way of packing that polygon.\n";
    }
    
}
