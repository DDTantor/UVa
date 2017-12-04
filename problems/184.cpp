#include <iostream>
#include <algorithm>
#include <tuple>
#include <set>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

#define eps 1e-6

struct point
{
    int x, y;
    point () {}
    point (int x, int y) : x(x), y(y) {}
    friend istream& operator >> (istream& in, point& p)
    {
        return in >> p.x >> p.y;
    }
    bool operator <(point& p) { return tie(x, y) < tie(p.x, p.y);}
} P[300];

int main()
{
    string s;
    while (cin >> P[0], P[0].x != 0 || P[0].y != 0)
    {
        set<pair<double, int> > S;
        int n = 1, cnt = 0;
        while (cin >> P[n], P[n].x != 0 || P[n].y != 0) ++n;

        
        sort(P, P + n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double ang = atan2((P[j].y - P[i].y), (P[j].x - P[i].x));
                
                vector<int> sol;
                for (int k = j + 1; k < n; ++k)
                {
                    double ang2 = atan2((P[k].y - P[i].y), (P[k].x - P[i].x));
                    if (ang2 == ang && S.insert({ang, k}).second)
                        sol.push_back(k);
                }

                if (sol.size())
                {
                    if (!cnt)
                        cout << "The following lines were found:\n";

                    ++cnt;
                    cout << '(' << setw(4) << P[i].x << ',' << setw(4) << P[i].y << ')';
                    cout << '(' << setw(4) << P[j].x << ',' << setw(4) << P[j].y << ')';
                    for (int k : sol)
                        cout << '(' << setw(4) << P[k].x << ',' << setw(4) << P[k].y << ')';
                    cout << '\n';
                }
            }
        }

        if (!cnt)
            cout << "No lines were found\n";
    }
}
