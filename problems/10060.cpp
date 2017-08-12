#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <sstream>

using namespace std;

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& a) {return in >> a.x >> a.y;}
};

double Area(vector<point>& P)
{
    double A = 0;
    for (int i = 0; i < P.size() - 1; ++i)
    {
        double x1 = P[i].x, x2 = P[i + 1].x;
        double y1 = P[i].y, y2 = P[i + 1].y;
        A += x1 * y2 - x2 * y1;
    }
    return 0.5 * fabs(A);
}

int main()
{
    int n;
    while (cin >> n, cin.ignore(), n)
    {
        double A = 0;
        for (int i = 0; i < n; ++i)
        {
            vector<point> P;
            string s;
            getline(cin, s);
            istringstream iss(s);
            double x, y, a;
            iss >> a;
            while (iss >> x >> y)
                P.emplace_back(x, y);
            
            A += a * Area(P);
        }
        double r, t;
        cin >> r >> t;
        int cnt = A / (M_PI * r * r * t);
        cout << cnt << endl;
    }
}
