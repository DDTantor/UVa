#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    point(){}
    friend istream& operator >>(istream& in, point& a) { return in >> a.x >> a.y;}
};

double dist(const point& A, const point& B)
{
    return hypot(A.x - B.x, A.y - B.y);
}

double Area(double a, double b, double c)
{
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Area(const point& A, const point& B, const point& C)
{
    return Area(dist(A, B), dist(B, C), dist(C, A));
}

int main()
{
    int t;
    point A, B, C;
    cin >> t;
    while (cin >> A >> B >> C, t--)
    {
        cout << (int)round(Area(A, B, C) / 7) << '\n';
    }
}
