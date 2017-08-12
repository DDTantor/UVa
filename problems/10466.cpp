#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int n, T;

int main()
{
    while (cin >> n >> T)
    {
        double cX = 0;
        double cY = 0;
        for (int i = 0; i < n; ++i)
        {
            double r, t;
            cin >> r >> t;
            double A = 2 * M_PI * T / t;
            cX += r * cos(A);
            cY += r * sin(A);
            double dist = hypot(cX, cY);
            if (i)
                cout << ' ';
            cout << fixed << setprecision(4) << dist;
        }
        cout << '\n';
    }
    
}
