#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    while (cin >> n, n)
    {
        int ind;
        double m = -1, h, w, M;
        for (int i = 1; i <= n; ++i)
        {
            cin >> h >> w;
            if (w > h)
                swap(h, w);
            double M = min(h / 4.0, w);
            M = max(M, min(h / 2.0, w / 2.0));
            if (M > m)
                m = M, ind = i;
        }
        cout << ind << '\n';
    }
}
