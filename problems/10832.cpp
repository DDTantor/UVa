#include <iostream>
#include <tuple>
#include <cmath>
#include <iomanip>

using namespace std;

struct point
{
    double x, y, z;
    point(){}
    point(double x, double y, double z) : x(x), y(y), z(z) {}
    friend istream& operator>>(istream& in, point& p)
    {
        return in >> p.x >> p.y >> p.z;
    }
} P[21];

int c, n;
double f, r, b, X[20], Y[20], Z[20];

double dist(double x, double y, double z)
{
    return sqrt(x * x + y * y + z * z);
}

double dist(point& a, point& b)
{
    return dist(a.x - b.x, a.y - b.y, a.z - b.z);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(2);
    P[0] = point(0, 0, 1);
    while (cin >> f >> b >> r >> n, f || b || r || n)
    {
        cout << "Mission " << ++c << ": "; 
        for (int i = 1; i <= n; ++i)
            cin >> P[i];

        for (int i = 0; i < n; ++i)
            for (int j = i + 2; j <= n; ++j)
                if (dist(P[i], P[j]) < dist(P[i], P[i + 1]))
                    swap(P[j], P[i + 1]);

        double traveled = 0, d = 0;
        bool fl = true;
        for (int i = 0; i < n && fl; ++i)
        {
            d = dist(P[i], P[i + 1]);
            traveled += d;
            if (b * traveled / r > f)
            {
                traveled -= d;
                double tmp = (f - b * traveled / r ) * r / b;
                traveled += tmp;
                d -= tmp;
                for (int j = i + 1; j < n; ++j)
                    d += dist(P[j], P[j + 1]);

                fl = false;
            }
        }

        if (fl)
            cout << "SUCCESS!! Time: " << traveled / r << "  Traveled: " << traveled << "  Fuel Left: " << f - b * traveled / r << endl;
        else
            cout << "FAILURE!! Traveled: " << traveled << "  From Home: " << d << endl;
    }
}
