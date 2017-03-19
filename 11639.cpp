#include <iostream>

using namespace std;

struct point
{
    int x, y;
    friend istream& operator >>(istream& in, point& a){return in >> a.x >> a.y;}
};

struct rectangle
{
    point p1, p2;
    friend istream& operator >>(istream& in, rectangle& r){return in >> r.p1 >> r.p2;}
};

int Intersection(const rectangle& R1, const rectangle& R2)
{
    int x1 = max(R1.p1.x, R2.p1.x);
    int y1 = max(R1.p1.y, R2.p1.y);
    int x2 = min(R1.p2.x, R2.p2.x);
    int y2 = min(R1.p2.y, R2.p2.y);
    if (x1 < x2 && y1 < y2)
        return (x2 - x1) * (y2 - y1);
    
    return 0;
}

int Area(const rectangle& R)
{
    return (R.p2.x - R.p1.x) * (R.p2.y - R.p1.y);
}

int main()
{
    int t, c = 1;
    cin >> t;
    while (t--)
    {
        cout << "Night " << c++ << ": ";
        rectangle G1, G2;
        cin >> G1 >> G2;
        int S = Intersection(G1, G2);
        int G = Area(G1) + Area(G2) - 2 * S;
        int N = 100 * 100 - G - S;
        cout << S << ' ' << G << ' ' << N << '\n';
    }
}
