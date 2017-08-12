#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int c = 1, d, v, u, t;
    cin >> t;
    cout << fixed << setprecision(3);
    while (t--)
    {
        cin >> d >> v >> u;
        cout << "Case " << c++ << ": ";
        if (v >= u)
            cout << "can't determine\n";
        else 
        {   
            double res = d / sqrt(u * u - v * v) - (double)d / u; 
            if (res)
                cout << res << '\n';
            else
                cout << "can't determine\n";
        }
    }
}
