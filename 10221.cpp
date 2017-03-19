#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double s, angle;
    string d;
    while (cin >> s >> angle >> d)
    {
        s += 6440;
        if (d == "min")
            angle /= 60;
            
        if (angle > 180)
            angle = 360 - angle;
        double Ldist = s * M_PI * angle / 180;
        double Cdist = 2 * s * sin(angle / 2.0 * M_PI / 180);
        cout << fixed << setprecision(6) << Ldist << ' ' << Cdist << '\n';
    }
    
}
