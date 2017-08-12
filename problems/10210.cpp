#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


struct point
{
    double x, y;
    point() {}
    friend istream& operator >> (istream& in, point& a) { return in >> a.x >> a.y;}
};

double dist(const point& A, const point& B)
{
    return hypot(A.x - B.x, A.y - B.y);
}

int main()
{
    point A, B;
    double alfa, beta;
    while (cin >> A >> B >> alfa >> beta)
    {
        double res = dist(A, B) * (1.0 / tan(alfa * M_PI / 180) + 1.0 / tan(beta * M_PI / 180));
        cout << fixed << setprecision(3) << res << '\n';
    }
}
