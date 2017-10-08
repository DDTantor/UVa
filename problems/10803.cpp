#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

#define inf 1e9

typedef pair<int, int> ii;
typedef vector<ii> vii;

int cs = 0, t, n;
double G[101][101], x, y;

double Close(ii& a, ii& b)
{
    double d = hypot(a.first - b.first, a.second - b.second);
    return (d <= 10.0? d : inf);
}

int main()
{
    cin >> t;
    while (t--)
    {
        cout << "Case #" << ++cs << ":\n";
        cin >> n;
        vii C;
        for (int i = 0; i < n; ++i)
            cin >> x >> y, C.emplace_back(x, y);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                G[i][j] = (i == j? 0 : inf);
        
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                G[i][j] = G[j][i] = Close(C[i], C[j]);

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    G[i][j] = min(G[i][j], G[i][k] + G[k][j]);

        double m = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                m = max(m, G[i][j]);

        if (m == inf)
            cout << "Send Kurdy\n\n";
        else
            cout << fixed << setprecision(4) << m << "\n\n";
        
    }
}
