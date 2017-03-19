#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    double n, r;
    while (cin >> r >> n)
    {
        double angle = 2 * M_PI / n;
        double A = n * r * r * sin(angle) / 2;
        cout << fixed << setprecision(3) << A << '\n';
    }
    
}
