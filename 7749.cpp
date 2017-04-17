#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double TtoC(int n)
{
    double d1 = hypot(n, 0.5 * sqrt(3) - 0.5);
    double d2 = sqrt(d1 * d1 - 0.25);
    double d3 = (0.5 * M_PI - atan2(0.5 * sqrt(3) - 0.5, n) - atan2(2.0 * d2, 1)) / 2.0;
    return d2 + d3;
}

double TtoS(int n)
{
    return hypot(1 - sqrt(3) / 2, n - 0.5) + 0.5;
}

int main()
{
    int n;
    cout << fixed << setprecision(11);
    while (cin >> n)
    {
        string in;
        cin >> in;
        int SC1 = in.find_first_of("SC"), SC2 = in.find_last_of("SC");
        if (SC1 == string::npos)
            cout << 2 * n + 1 << '\n';
        else
        {
            int T1 = in.find_first_of("T"), T2 = in.find_last_of("T");
            double res = 2 * (SC2 - SC1);
            //Lijevi rub
            if (SC1 == 0)
                res += (in[0] == 'S' ? 2 : M_PI / 2.0);
            else
                res += (0.5 +  SC1 + 1 + (in[SC1] == 'S' ? TtoS(SC1) : TtoC(SC1)));
            //Desni rub
            if (SC2 == n - 1)
                res += (in[n - 1] == 'S' ? 2 : M_PI / 2.0);
            else
                res += (0.5 + (n - SC2 - 1) + 1  + (in[SC2] == 'S' ? TtoS(n - SC2 - 1) : TtoC(n - SC2 - 1)));
            cout << res << '\n';
        }
    }
}
