#include <iostream>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        double sum = 0, a, b, c, d;
        string s;
        cin >> a >> b;
        cin.ignore();
        while (getline(cin, s) && s != "")
        {
            istringstream iss(s);
            iss >> a >> b >> c >> d;
            sum += 0.0001 * hypot(a - c, b - d);
        }

        int h = sum;
        double r = (sum - h) * 60;
        int m = r;
        r -= m;
        if (r > 0.5)
            ++m;

        if (m == 60)
            h++, m = 0;

        cout << h << ":" << setw(2) << setfill('0') << m << "\n";
        if (t) cout << '\n';
    }
}
