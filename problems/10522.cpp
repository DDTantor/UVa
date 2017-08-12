#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        double h1, h2, h3;
        cin >> h1 >> h2 >> h3;
        if (h1 <= 0 || h2 <= 0 || h3 <= 0)
        {
            t--;
            cout << "These are invalid inputs!\n";
            continue;
        }
        double p1 = 1 / h1 + 1 / h2 + 1 / h3;
        double p2 = 1 / h1 - 1 / h2 + 1 / h3;  
        double p3 = 1 / h1 + 1 / h2 - 1 / h3;
        double p4 = -1 / h1 + 1 / h2 + 1 / h3;
        if (p1 <= 0.0 || p2 <= 0.0 || p3 <= 0.0 || p4 <= 0.0)  
        {
            t--;
            cout << "These are invalid inputs!\n";
        }
        else
            cout << fixed << setprecision(3) << 1 / sqrt(p1 * p2 * p3 * p4) << '\n';
    }
}
