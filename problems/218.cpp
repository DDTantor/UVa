#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

struct point
{
    double x, y;
    friend istream& operator >> (istream& in, point& p) {return in >> p.x >> p.y;}
    bool operator <(const point& p) {return x < p.x || (x == p.x && y < p.y);}
};

double cross(const point& o, const point& a, const point& b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
} 

double dist(const point& a, const point& b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

vector<point> ConvexHull(vector<point>& P)
{
    int n = P.size(), k = 0;
    if (n == 1) return P;
    vector<point> H(2 * n);
    
    sort(P.begin(), P.end());
    
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    
    for (int i = n - 2, t = k + 1; i >= 0; --i)
    {
        while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) < 0)
            k--;
        H[k++] = P[i];
    }
    
    H.resize(k);
    return H;
}

using namespace std;

int main()
{
    int n, c = 1;;
    while (cin >> n, n)
    {
        if (c != 1) 
            cout << '\n';
        
        cout << "Region #" << c++ << ":\n";
        vector<point> P(n);
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        P = ConvexHull(P);
        double per = 0;
        for (int i = 1; i < P.size(); ++i)
            per += dist(P[i], P[i - 1]);
    
        for (auto it = P.rbegin(); it != P.rend(); ++it)
        {
            if (it != P.rbegin())
                cout << '-';
            cout << fixed << setprecision(1) << '(' << (*it).x << ',' << (*it).y << ')';
        }
        cout << fixed << setprecision(2) << "\nPerimeter length = " << per << '\n';
    }
}
