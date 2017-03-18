#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        
        double x = 0, y = 0, angle = 0;
        for (int i = 0; i < n; ++i)
        {
            string c;
            double p; 
            cin >> c >> p;
            if (c == "fd" || c == "bk")
            {
                int sign = (c == "fd"? 1 : -1);
                x += cos(angle / 180 * M_PI) * sign * p;
                y += sin(angle / 180 * M_PI) * sign * p;
            }
            else if (c == "rt" || c == "lt")
            {
                int sign = (c == "lt"? 1 : -1);
                angle += p * sign;
            }
        }
        double dist = hypot(x, y);
        cout << fixed << setprecision(0) << dist << '\n'; 
    }
}
