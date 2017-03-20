#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >>(istream& in, point& p) {return in >> p.x >> p.y;}
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

int main()
{
    point A, B, C;
    while (cin >> A >> B >> C)
    {
        double h, k, r, c, d, e, alfa, beta, gama;
        
        r = norm(A - B) * norm(B - C) * norm(C - A) / (2.0 * fabs(cross(A - B, B - C)));
        
        alfa = snorm(B - C) * dot(A - B, A - C) / (2.0 * fabs(cross(A - B, B - C) * cross(A - B, B - C)));
        beta = snorm(A - C) * dot(B - A, B - C) / (2.0 * fabs(cross(A - B, B - C) * cross(A - B, B - C)));
        gama = snorm(A - B) * dot(C - A, C - B) / (2.0 * fabs(cross(A - B, B - C) * cross(A - B, B - C)));
        
        h = alfa * A.x + beta * B.x + gama * C.x;
        k = alfa * A.y + beta * B.y + gama * C.y;
        
        e = h * h + k * k - r * r;
        d = -2 * k;
        c = -2 * h;
        
        cout << fixed << setprecision(3);
        if (h == 0)
            cout << "x^2 + ";
        else
            cout << "(x " << (h < 0? "+ " : "- ") << fabs(h) << ")^2 + ";
        if (k == 0)
            cout << "y^2 = " << r << "^2\n";
        else
            cout << "(y " <<  (k < 0? "+ " : "- ") << fabs(k) << ")^2 = " << r << "^2\n";
            
        cout << "x^2 + y^2 ";
        if (c != 0)
            cout << (c < 0? "- " : "+ ") << fabs(c) << "x "; 
        if (d != 0)
            cout << (d < 0? "- " : "+ ") << fabs(d) << "y ";
        if (e != 0)
            cout << (e > 0? "+ " : "- ") << fabs(e) << ' ';
        cout << "= 0\n";
        if (cin.peek() != EOF)
            cout << '\n';
    }
}
