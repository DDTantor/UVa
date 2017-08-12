#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    point() {}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& a) { return in >> a.x >> a.y; }
};

double cross(point& o, point& a, point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool Intersect(point& s1, point& e1, point& s2, point& e2)
{
    return cross(s1, e1, s2) * cross(s1, e1, e2) <= 0 &&
           cross(s2, e2, s1) * cross(s2, e2, e1) <= 0;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<point> PE(n), PS(n);
        for (int i = 0; i < n; ++i)
            cin >> PS[i] >> PE[i];
            
        int V[1000] = {};
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                if (Intersect(PS[i], PE[i], PS[j], PE[j]))
                    V[i]++, V[j]++;
        int sum = 0;
        for (int i = 0; i < n; ++i)
            sum += (V[i] ? V[i] : 4);
            
        cout << sum / 2 << '\n';
    }
}
