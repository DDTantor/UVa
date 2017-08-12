#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<float> vf;

int main()
{
    int f, r, F[10], R[10];
    while (cin >> f >> r, f)
    {
        vf res;
        for (int i = 0; i < f; ++i)
            cin >> F[i];
        for (int i = 0; i < r; ++i)
            cin >> R[i];
        for (int i = 0; i < f; ++i)
            for (int j = 0; j < r; ++j)
                res.push_back((float)R[j] / F[i]);
        sort(res.begin(), res.end());
        float best = 0;
        for (int i = 1; i < res.size(); ++i)
            if (res[i] / res[i - 1] > best)
                best = res[i] / res[i - 1];
        cout << fixed << setprecision(2) << best << '\n';
    }
}
