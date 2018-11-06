#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <iomanip>
#include <sstream>

using namespace std;

typedef tuple<double, double, int> pt;

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        vector<pt> P;
        for (int i = 0; i < n; ++i)
        {
            double x1, x2, p;
            cin >> x1 >> p >> x2 >> p >> p;
            if (x1 > x2)
                swap(x1, x2);
            
            P.emplace_back(x1, p, 0);
            P.emplace_back(x2, p, 1);
        }

        
        sort(P.begin(), P.end());
        double val, currp = 1, prevx = -1e9, currx;
        int id, cnt = 1;
        ostringstream oss;
        oss << fixed << setprecision(3);
        for (pt p : P)
        {
            tie(currx, val, id) = p;
            if (currx != prevx)
            {
                ++cnt;
                if (prevx == -1e9)
                    oss << "-inf " << currx << ' ' << currp << '\n';
                else
                    oss << prevx << ' ' << currx << ' ' << currp << '\n';
            }

            if (id)
                currp /= val;
            else
                currp *= val;
            
            prevx = currx;
        }

        oss << currx << " +inf 1.000\n";
        cout << cnt << '\n' << oss.str();
        if (t)
            cout << '\n';
    }
}
