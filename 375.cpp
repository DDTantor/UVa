#include <iostream>
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    double H, B;
    cin >> t;
    while(cin >> B >> H, t--)
    {
        double A = hypot(0.5 * B, H);
        double r = B * H / (A + B + A);
        double c = 0;
        while (r >= 0.000001)
        {
            c += 2 * r * M_PI;
            double tmp = H;
            H -= 2 * r;
            r *= H / tmp;
        }
        cout << setw(13) << fixed << setprecision(6) << c << '\n';
        if (t)
            cout << '\n';
    }
}
