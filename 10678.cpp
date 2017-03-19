#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int t;
    double L, D;
    cin >> t;
    while (cin >> D >> L, t--)
    {
        L /= 2.0;
        double B = sqrt(L * L - D * D / 4.0);
        double Area = M_PI * B * L;
        cout << fixed << setprecision(3) << Area << '\n';
    }
}
