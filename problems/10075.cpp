#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

typedef pair<double, double> cord;

const int r = 6378;
const int maxn = 100;
const double inf = 1e9;

int n, m, q, c = 0;
double D[maxn][maxn];
vector<cord> C;

unordered_map<string, int> M;

double dist(int u, int v)
{
    double utheta, vtheta, uphi, vphi;
    tie(utheta, uphi) = C[u];
    tie(vtheta, vphi) = C[v];
    
    return r * acos(sin(utheta) * sin(vtheta) + cos(utheta) * cos(vtheta) * cos(uphi - vphi));
}

int main()
{
    int n, m, q, c = 0;
    while (cin >> n >> m >> q, n || m || q)
    {
        M.clear();
        C.clear();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                D[i][j] = (i == j? 0 : inf);
                    
        cout << "Case #" << ++c << '\n';
        string a, b;
        double alphax, alphay;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> alphax >> alphay;
            M.emplace(a, i);
            C.emplace_back(alphax * M_PI / 180.0, alphay * M_PI / 180.0);
        }
        
        for (int i = 0; i < m; ++i)
        {
            cin >> a >> b;
            int u = M[a], v = M[b];
            D[u][v] = round(dist(u, v));
        }

        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);

        for (int i = 0; i < q && cin >> a >> b; ++i)
        {
            int u = M[a], v = M[b];
            if (D[u][v] != inf)
                cout << D[u][v] << " km\n";
            else
                cout << "no route exists\n";
        }

        cin.ignore();
        if (cin.peek() != '0')
            cout << '\n';
    }
}
