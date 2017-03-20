#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define eps 1e-6

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& a){return in >> a.x >> a.y;}
    point operator -(point a){return point(x - a.x, y - a.y);}
};

struct rectangle
{
    point p1, p2;
    friend istream& operator >> (istream& in, rectangle& r){return in >> r.p1 >> r.p2;}
}R[10];

struct triangle
{
    point p1, p2, p3;
    friend istream& operator >> (istream& in, triangle& t){return in >> t.p1 >> t.p2 >> t.p3;}
}T[10];

struct circle
{
    double r, x1, y1;
    friend istream& operator >> (istream& in, circle& c){return in >> c.x1 >> c.y1 >> c.r;}
}C[10];

bool is;

double dot(point a, point b)
{
    return a.x * b.x + a.y * b.y;
}

double snorm(point a)
{
    return a.x * a.x + a.y * a.y;
}

double angle(point a, point o, point b)
{
    return acos(dot(a - o, b - o) / sqrt(snorm(a - o) * snorm(b - o)));
}

bool InsideTriangle(const point& P, const triangle& T)
{
    double angle1 = angle(T.p1, P, T.p2);
    double angle2 = angle(T.p2, P, T.p3);
    double angle3 = angle(T.p3, P, T.p1);
    return fabs((angle1 + angle2 + angle3) - 2 * M_PI) < eps
            && angle1 < M_PI && angle2 < M_PI && angle3 < M_PI;
}

bool InsidePolygon(const point& P, const rectangle& R)
{
    is |= (P.x > R.p1.x && P.x < R.p2.x && P.y < R.p1.y && P.y > R.p2.y);
    return (P.x > R.p1.x && P.x < R.p2.x && P.y < R.p1.y && P.y > R.p2.y);
}

bool InsideCircle(const point& P, const circle& C)
{
    is |= (hypot(P.x - C.x1, P.y - C.y1) < C.r);
    return (hypot(P.x - C.x1, P.y - C.y1) < C.r);
}

int main()
{
    char c;
    int n = 0;
    while (cin >> c, c != '*')
    {
        if (c == 'r')
            cin >> R[n++];
        else if (c == 'c')
            cin >> C[n++];
        else 
            cin >> T[n++];
    }    
    point A;
    int m = 1;
    while (cin >> A, A.x != 9999.9 && A.y != 9999.9)
    {
        is = false;
        for (int i = 0; i < n; ++i)
            if (InsidePolygon(A, R[i]) || InsideCircle(A, C[i]) || InsideTriangle(A, T[i]))
                cout << "Point " << m << " is contained in figure " << i + 1 << '\n';
                
        if (!is)
            cout << "Point " << m << " is not contained in any figure\n";
            
        m++;
    }
}
