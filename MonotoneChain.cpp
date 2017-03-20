#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

struct point
{
    double x, y;
    friend istream& operator >>(istream& in, point& p){return in >> p.x >> p.y;}
    bool operator <(const point& p){return x < p.x || (x == p.x && y < p.y);}
};

double cross(point o, point a, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

int ConvexHull(int n, point P[], point CH[])
{
    sort(P, P + n);
    int i, m = 0, t;
    for (i = 0; i < n; ++i)
    {
        while (m >= 2 && cross(CH[m - 2], CH[m - 1], P[i]) < 0)
            m--;
        CH[m++] = P[i];
    }
    for (i = n - 2, t = m + 1; i >= 0; i--)
    {
        while (m >= t && cross(CH[m - 2], CH[m - 1], P[i]) < 0)
            m--;
            
        CH[m++] = P[i];
    }
    return m - 1;
}

int main()
{
    point P[401], CH[401];
    char c;
    string s;
    int p, i, j, k;
    while (cin.ignore(2), getline(cin, s), s != "D")
    {
        cout << s << " convex hull:\n";
        int n = 0, m;
        while (cin.peek() != 'S' && cin.peek() != 'E')
        {
            getline(cin, s);
            istringstream iss(s);
            iss >> c >> p;
            for (int i = 0; i < p; ++i)
                iss >> P[n++];
        }
        sort(P, P + n);
        for (i = 1, j = 0; i < n; ++i)
            if (P[j].x != P[i].x || P[j].y != P[i].y)
                P[++j] = P[i];
                
        n = j + 1;
        m = ConvexHull(n, P, CH);
        int pos = 0;
        for (i = 0; i < m; ++i)
            if (CH[i].x > CH[pos].x || (CH[i].x == CH[pos].x && CH[i].y < CH[pos].y))
                pos = i;
        
        for (int i = 0; i < m; ++i)
            cout << " (" << CH[(i + pos) % m].x << ',' << CH[(i + pos) % m].y << ')';
            
        cout << '\n';
    }
}
