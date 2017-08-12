#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>

using namespace std;


int main()
{
    int c;
    double r1, r2, t, r, res;
    string s;
    cin >> c;
    cin.ignore();
    while (c--)
    {
        getline(cin, s);
        istringstream iss(s);
        if(s.size() >= 3)
        {
            iss >> r1 >> r2;
            res = 2 * r1 * r2 * M_PI;
        }
        else
        {
            iss >> t;
            res = t * t * M_PI / 8;
        }
        cout << fixed << setprecision(4) << res << '\n';
        
    }
    
}
