#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    point(){}
    friend istream& operator >> (istream& in, point& a){return in >> a.x >> a.y;}
};

struct rectangle
{
    point p1, p2;
    friend istream& operator >> (istream& in, rectangle& r){return in >> r.p1 >> r.p2;}
}R[10];

struct circle
{
    double r, x1, y1;
    friend istream& operator >> (istream& in, circle& c){return in >> c.x1 >> c.y1 >> c.r;}
}C[10];

bool is;

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
        else
            cin >> C[n++];
    }    
    point A;
    int m = 1;
    while (cin >> A, A.x != 9999.9 && A.y != 9999.9)
    {
        is = false;
        for (int i = 0; i < n; ++i)
            if (InsidePolygon(A, R[i]) ||InsideCircle(A, C[i]))
                cout << "Point " << m << " is contained in figure " << i + 1 << '\n';
                
        if (!is)
            cout << "Point " << m << " is not contained in any figure\n";
            
        m++;
    }
}
