#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double x1, x2, y1, y2;
    while (cin >> x1 >> y1 >> x2 >> y2)
        cout << fixed << setprecision(10) << -y2 + (y2 + y1) / 2 + (x2 + x1) / 2 << ' ' << x2 + (y2 + y1) / 2 - (x2 + x1) / 2 << ' ' 
                                          << -y1 + (y2 + y1) / 2 + (x2 + x1) / 2 << ' ' << x1 + (y2 + y1) / 2 - (x2 + x1) / 2 << '\n';
}
