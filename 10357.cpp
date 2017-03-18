#include <iostream>
#include <cmath>

using namespace std;

struct player
{
    int x, y, v;
    friend istream& operator >>(istream& in, player& a) { return in >> a.x >> a.y >> a.v;}    
}P[1005];

int main()
{
    int p, n, x, y, z, a, b, c, d, e, f, g, t;
    cin.ignore(8);
    cin >> p;
    for (int i = 0; i < p; ++i)
        cin >> P[i];
    
    cin.ignore(7);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a >> b >> c >> d >> e >> f >> g;
        for (t = 1; a * t * t + b * t + c > 0; ++t) {}
        x = d * t + e;
        y = f * t + g;
        if(t < 0) t = 0;
        cout << "Ball " << i + 1 << " was ";
        if (x < 0 || y < 0)
            cout << "foul at (" << x << ',' << y << ")\n";
        else 
        {
            bool flag = false;
            for (int i = 0; i < p; ++i)
                flag |= (hypot(x - P[i].x, y - P[i].y) < t * P[i].v);
    
            if (flag)
                cout << "caught";
            else
                cout << "safe";
                
            cout << " at (" << x << ',' << y << ")\n";
        }
    }
    
}
