#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


int main()
{
    while (true)
    {
        int leak = 0, p = 0, pret = 0;
        double res = 0, max = 0;
        while (true)
        {
            int n;
            string s;
            cin >> n >> s;
            res = res + (n - pret) * (leak + p / 100.0);
            if (s == "Goal")
                break;
            else if (s == "Fuel")
                cin >> s >> p;
            else if (s == "Leak")
                leak++;
            else if (s == "Mechanic")
                leak = 0;
            else if (s == "Gas")
            {
                cin >> s;
                if (res > max)
                    max = res;
                res = 0;
            }
            if (p == 0)
                return 0;
            pret = n;
        }
        res = (max > res? max : res);
        cout << fixed << setprecision(3) << res << '\n';
    }
}
