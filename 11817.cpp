#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double r = 6371009.0;

//(r * cos(phi) * sin(theta), r * sin(phi) * sin(theta), r * cos(theta));

int main()
{
    int t;
    double latA, latB, lonA, lonB;
    cin >> t;
    while (cin >> latA >> lonA >> latB >> lonB, t--)
    {
        double phiA = lonA * M_PI / 180.0;
        double phiB = lonB * M_PI / 180.0;
        double thetaA = latA * M_PI / 180.0;
        double thetaB = latB * M_PI / 180.0;
        
        double x1 = r * cos(phiA) * cos(thetaA);
        double y1 = r * sin(phiA) * cos(thetaA);
        double z1 = r * sin(thetaA);
        
        double x2 = r * cos(phiB) * cos(thetaB);
        double y2 = r * sin(phiB) * cos(thetaB);
        double z2 = r * sin(thetaB);
        
        double res = hypot(z1 - z2, hypot(x1 - x2, y1 - y2));
        double arc = r * 2 * asin(res / (2 * r));
        cout << (int)round(arc - res) << '\n';
    }
}
