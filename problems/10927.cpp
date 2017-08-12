#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x, y, h;
    bool vis = true;
    point(){}
    point(double x, double y, double h) : x(x) , y(y), h(h) {}
    friend istream& operator >> (istream& in, point& p)
    {
        return in >> p.x >> p.y >> p.h;
    }
    bool operator <(point& b) const
    {
        return hypot(x, y) < hypot(b.x, b.y);
    }
};

bool cmp(point& a, point& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int main()
{
    int n, t = 1;
    while (cin >> n, n)
    {
        cout << "Data set " << t++ << ":\n";
        map<double, vector<point> >M;
        vector<point> P(n);
        double x, y, h, theta;
        for (int i = 0; i < n; ++i)
            cin >> P[i];
        
        sort(P.begin(), P.end());
        for (int i = 0; i < n; ++i)
        {
            theta = atan2(P[i].y, P[i].x);
            M[theta].emplace_back(P[i].x, P[i].y, P[i].h);
        }
        
        vector<point> V;
        
        for (auto A : M)
        {
            double mx = A.second[0].h;
            for (int i = 1; i < A.second.size(); ++i)
            {
                if (A.second[i].h <= mx)
                    V.push_back(A.second[i]);
                mx = max(mx, A.second[i].h);
            }
        }
        
        for (int i = 0; i < P.size(); ++i)
            if(!P[i].vis)
                V.push_back(P[i]);
    
        sort(V.begin(), V.end(), cmp);
        if (!V.size())
            cout << "All the lights are visible.\n";
        else
        {
            cout << "Some lights are not visible:\n";
            for (int i = 0; i < V.size(); ++i)
                cout << "x = " << V[i].x << ", y = " << V[i].y << (i + 1 == V.size()? ".\n" : ";\n");
        }
    }
}
