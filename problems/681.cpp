#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

struct point
{
    double x, y;
    point(){}
    friend istream& operator >> (istream& in, point& a) {return in >> a.x >> a.y;}
    bool operator <(const point& p) {return x < p.x || (x == p.x && y < p.y);}
};

double cross(const point& o, const point& a, const point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

vector<point> ConvexHull(vector<point> P)
{
    int n = P.size(), k = 0;
    if (n == 1)
        return P;
        
    vector<point> H(2 * n);
    
    sort(P.begin(), P.end());
    
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(H[k - 2], H[k - 1], P[i]) <= 0)
            k--;
        H[k++] = P[i];
    }
    
    H.resize(k - 1);
    return H;
}

int main()
{
    int t;
    cin >> t;
    cout << t << '\n';
    while (t--)
    {
        int n;
        cin >> n;
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        P = ConvexHull(P);
        cout << P.size() + 1 << '\n';
        
        int ind, minx = INT_MAX, miny = INT_MAX;
        for (int i = 0; i < P.size(); ++i)
            if (P[i].y < miny || (P[i].y == miny && P[i].x < minx))
                minx = P[i].x, miny = P[i].y, ind = i;
        
        n = P.size();
        for (int i = 0; i < P.size() + 1; ++i)
            cout << P[(i + ind) % n].x << ' ' << P[(i + ind) % n].y << '\n';
        
          
        if (t)
            cin >> n, cout << n << '\n';
    }
}
