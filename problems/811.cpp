#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip> 

using namespace std;

#define eps 1e-6

typedef long long ll;

const int maxn = 15;

struct point
{
    int x, y, v, l;
    point(){}
    point(int x, int y, int v, int l) : x(x), y(y), v(v), l(l) {}
    friend istream& operator>>(istream& in, point& p)
    {
        return in >> p.x >> p.y >> p.v >> p.l;
    }
    bool operator<(point& p)
    {
        return x < p.x;
    }
} P[maxn];

struct forest
{
    int val;
    double exl;
    vector<int> cut;
    forest(){}
    forest(int val, double exl, vector<int> cut) : val(val), exl(exl), cut(cut) {}
    bool operator <(forest f)
    {
        return val < f.val;
    }
    
};

int cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

vector<point> ConvexHull(vector<point>& P)
{
    if (P.size() < 3)
        return P;
    sort(P.begin(), P.end());
    vector<point> H;
    for (int i = 0; i < 2; ++i)
    {
        int s = H.size();
        for (point p : P)
        {
            while (H.size() >= s + 2 && cross(H[H.size() - 2], H[H.size() - 1], p) <= 0)
                H.pop_back();
            
            H.push_back(p);
        }
        
        if (!i) H.pop_back();
        reverse(P.begin(), P.end());
    }
    
    return H;
}

double Perimeter(vector<point>& P)
{
    double res = 0;
    for (int i = 1; i < P.size(); ++i)
        res += dist(P[i], P[i - 1]);

    if (P.size() == 2)
        res *= 2;
    
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int n, cs = 1;
    while (cin >> n, n)
    {
        if (cs != 1)
            cout << '\n';
        
        vector<forest> F;
        cout << "Forest " << cs++ << '\n';
                                     
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        for (ll i = 1; i < (1 << n); ++i)
        {
            int val = 0, len = 0;
            vector<point> Q;
            vector<int> cut;
            for (ll j = 0; j < n; ++j)
            {
                if ((1 << j) & i)
                    Q.push_back(P[j]);
                else
                    val += P[j].v, len += P[j].l, cut.push_back(j + 1);
            }

            Q = ConvexHull(Q);
            double exl = len - Perimeter(Q);
            if (exl > -eps)
                F.emplace_back(val, exl, cut);
        }

        sort(F.begin(), F.end());
        cout << "Cut these trees:";
        for (int i : F[0].cut)
            cout << ' ' << i;
        
        cout << "\nExtra wood: " << F[0].exl << '\n';
    }
}
