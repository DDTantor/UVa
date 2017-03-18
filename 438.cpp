#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
    double x, y;
    point(){}
    friend istream& operator >>(istream& in, point& a) {return in >> a.x >> a.y;}
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

double rCircCircle(double a, double b, double c)
{
    return a * b * c / (4.0 * Area(a, b, c));
}

double rCircCircle(const point& A, const point& B, const point& C)
{
    return rCircCircle(dist(A, B), dist(B, C), dist(C, A));
}

double Circumference(const point& A, const point& B, const point& C)
{
    return 2.0 * rCircCircle(A, B, C) * M_PI;
}

int main()
{
    point A, B, C;
    while (cin >> A >> B >> C)
            cout << fixed << setprecision(2) << Circumference(A, B, C) << '\n';
}
