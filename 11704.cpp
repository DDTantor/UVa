#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point
{
    double x, y;
    int type;
    point() {}
};

bool cmp(const point& a, const point& b)
{
    return atan2(a.y, a.x) < atan2(b.y, b.x);
}

double cross(point& a, point& b)
{
    return a.x * b.y - a.y * b.x;
}

bool iscut(int c, int p, vector<point>& P, int n)
{
    sort(P.begin(), P.end(), cmp);
    int cntc = 0, cntp = 0, cut = 0;
    //First cut
    (P[0].type ? cntc : cntp) += 1;
    for (int i = 1; i < n; ++i)
    {
        if (cross(P[0], P[i]) > 0)
            (P[i].type ? cntc : cntp) += 1;
        else
        {
            cut = i;
            break;
        }
    }
    
    if (cntc == c && cntp == p)
        return true;
        
    //Rotate cut
    for (int i = 1; i < n; ++i)
    {
        (P[i - 1].type ? cntc : cntp) -= 1;
        while (cross(P[i], P[cut]) > 0)
            (P[cut].type ? cntc : cntp) += 1, cut = (cut + 1) % n;
        if (cntc == c && cntp == p)
            return true;
    }
    return false;
}

int main()
{
    int c, p;
    while (cin >> c >> p, c != -1 || p != -1)
    {
        int n = 0, type;
        vector<point> P(p + c);
        for (int i = 0; i < c; ++i)
            cin >> P[n].x >> P[n].y, P[n++].type = 1;
            
        for (int i = 0; i < p; ++i)
            cin >> P[n].x >> P[n].y, P[n++].type = 0;
        
        cout << (iscut(c / 2, p / 2, P, n) ? "YES\n" : "NO\n");
    }
}
