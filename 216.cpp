#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <climits>
#include <cmath>
#include <iomanip>

using namespace std;


int n, cs = 0, X[8], Y[8];
double D[64][64];

int main()
{
    while (cin >> n, n)
    {
        cout << "**********************************************************\n";
        for (int i = 0; i < n; ++i)
            cin >> X[i] >> Y[i];

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = hypot(X[i] - X[j], Y[i] - Y[j]) + 16;

        vector<int> p(n), bestp(n);
        iota(p.begin(), p.end(), 0);
        double best = INT_MAX;
        do
        {
            double dist = 0;
            for (int i = 1; i < n; ++i)
                dist += D[p[i - 1]][p[i]];

            if (dist < best)
                best = dist, bestp = p;
        } while(next_permutation(p.begin(), p.end()));

        cout << fixed << setprecision(2);
        cout << "Network #" << ++cs << '\n';
        for (int i = 1; i < n; ++i)
            cout << "Cable requirement to connect (" << X[bestp[i - 1]] << ',' << Y[bestp[i - 1]] << ") to (" <<  X[bestp[i]] << ',' << Y[bestp[i]] << ") is " << D[bestp[i - 1]][bestp[i]] << " feet.\n";
        cout << "Number of feet of cable required is " << best << ".\n";
    }
}
