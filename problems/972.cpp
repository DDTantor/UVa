#include <iostream>
#include <iomanip> 
#include <algorithm>

using namespace std;

struct point
{
    double x, y;
    point(){}
} F[100], G[100];

int main()
{
    cout << fixed << setprecision(3);
    int m, n;
    double Px[400];
    while (cin >> n)
    {
        double prevx = 0, x;
        int cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> F[i].y >> x;
            F[i].x = prevx + x;
            prevx += x;
            Px[cnt++] = prevx;
        }
                
        cin >> m;
        prevx = 0;        
        for (int i = 0; i < m; ++i)
        {
            cin >> G[i].y >> x;
            G[i].x = prevx + x;
            prevx += x;
            Px[cnt++] = prevx;
        }

        double res = 1e9;
        int f = 0, g = 0;
        sort(Px, Px + cnt);
        for (int i = 0; i < cnt - 1; ++i)
        {
            while (F[f].x < Px[i]) ++f;
            while (G[g].x < Px[i]) ++g;
            res = min(res, max(F[f].y, G[g].y));
        }
        
        cout << res << '\n';
    }
}
