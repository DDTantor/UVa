#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

typedef vector<int> vi;

int main()
{
    int y, p;
    while (cin >> y >> p)
    {
        vi P(p);
        for (int i = 0; i < p; ++i)
            cin >> P[i];
        int bl, bo, b = 0; 
        for (int i = p - 1; P[i] >= y; --i)
        {
            auto ub = lower_bound(P.begin(), P.end(), P[i] - y + 1);
            if (i - (ub - P.begin()) + 1 >= b)
                b = i - (ub - P.begin()) + 1, bo = P[i], bl = P[ub - P.begin()];
        }
        cout << b << ' ' << bl << ' ' << bo << '\n';
        
    }
}
