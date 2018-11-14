#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    double W, L, theta;
    cin >> t;
    while (cin >> L >> W >> theta, t--)
    {
        theta *= M_PI / 180;
        double A = L / cos(theta);
        double alpha = sin(theta) * A / W;
        double C = (alpha - floor(alpha)) * W;
        if (int(floor(alpha)) % 2) C = W - C;
        double B = hypot(C, L);
        cout << fixed << setprecision(3) << A / B << '\n';
    }
}
