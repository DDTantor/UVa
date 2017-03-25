#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& p) {return in >> p.x >> p.y;}
    point operator -(point a) {return point(x - a.x, y - a.y);}
};


double cross(point a, point b)
{
    return a.x * b.y - a.y * b.x;
}

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double norm(point a)
{
    return hypot(a.x, a.y);
}

double snorm(point a)
{
    return a.x * a.x + a.y * a.y;
}

point FindCenter(point& A, point& B, point& C)
{
    double alfa, beta, gama;
    point o;
     
    alfa = snorm(B - C) * dot(A - B, A - C) / (2.0 * fabs(cross(A - B, B - C) * cross(A - B, B - C)));
    beta = snorm(A - C) * dot(B - A, B - C) / (2.0 * fabs(cross(A - B, B - C) * cross(A - B, B - C)));
    gama = snorm(A - B) * dot(C - A, C - B) / (2.0 * fabs(cross(A - B, B - C) * cross(A - B, B - C)));
    
    o.x = alfa * A.x + beta * B.x + gama * C.x;
    o.y = alfa * A.y + beta * B.y + gama * C.y;
    
    return o;
}

point rotate(point& A, double angle, point& o)
{
    point tmp;
    tmp.x = (A.x - o.x) * cos(angle) - (A.y - o.y) * sin(angle) + o.x;
    tmp.y = (A.x - o.x) * sin(angle) + (A.y - o.y) * cos(angle) + o.y;
    return tmp;
}

int main()
{
    int n, c = 1;
    point A, B, C;
    while (cin >> n, n)
    {
        cin >> A >> B >> C;
        point o = FindCenter(A, B, C), next = A;
        double minx, maxx, miny, maxy;
        minx = maxx = A.x;
        miny = maxy = A.y;
        double theta = 2 * M_PI / n;
        for (int i = 0; i < n; ++i)
        {
            next = rotate(next, theta, o);
            minx = min(minx, next.x);
            miny = min(miny, next.y);
            maxx = max(maxx, next.x);
            maxy = max(maxy, next.y);
        }
        
        cout << fixed << setprecision(3) << "Polygon " << c++ << ": " << (maxx - minx) * (maxy - miny) << '\n'; 
    }
}
