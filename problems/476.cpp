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

bool is;

bool InsidePolygon(const point& P, const rectangle& R)
{
    is |= (P.x > R.p1.x && P.x < R.p2.x && P.y < R.p1.y && P.y > R.p2.y);
    return (P.x > R.p1.x && P.x < R.p2.x && P.y < R.p1.y && P.y > R.p2.y);
}


int main()
{
    char c;
    int n = 0;
    while (cin >> c, c != '*')
        cin >> R[n++];
        
    point A;
    int m = 1;
    while (cin >> A, A.x != 9999.9 && A.y != 9999.9)
    {
        is = false;
        for (int i = 0; i < n; ++i)
            if (InsidePolygon(A, R[i]))
                cout << "Point " << m << " is contained in figure " << i + 1 << '\n';
                
        if (!is)
            cout << "Point " << m << " is not contained in any figure\n";
            
        m++;
    }
}
