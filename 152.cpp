#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <climits>

using namespace std;

struct point { double x, y, z;
    point() { x = y = z = 0.0; }
    point(double x, double y, double z) : x(x), y(y), z(z) {}
};

typedef vector<point> vp;

double dist (point A, point B)
{
    double dx = A.x - B.x, dy = A.y - B.y, dz = A.z - B.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

int main()
{
    int x, y, z, d, Res[10] = {};
    vp P;
    while (cin >> x >> y >> z, x || y || z)
        P.push_back(point(x, y, z));
    
    
    for (int i = 0; i < P.size(); ++i)
    {
        int min = INT_MAX;
        for (int j = 0; j < P.size(); ++j)
        {
            if (i == j)
                continue;
                
            d = dist(P[i], P[j]), min = (d < min? d : min);
        }
        
        if (min < 10)
            Res[min]++;
    }
    
    for (int i = 0; i < 10; ++i)
        cout << setw(4) << setfill(' ') << Res[i];
    
    cout << '\n';
}
