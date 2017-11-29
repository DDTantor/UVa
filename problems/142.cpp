#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define eps 1e-6

struct point
{
    int x, y;
    point () {}
    point (int x, int y) : x(x), y(y) {}
    friend istream& operator >>(istream& in, point& p)
    {
        return in >> p.x >> p.y;
    }
    
} I[50];

struct rec
{
    int lx, ly, rx, ry;
    rec () {}
    rec (int lx, int ly, int rx, int ry) :
        lx(lx), ly(ly), rx(rx), ry(ry) {}
    friend istream& operator >>(istream& in, rec& r)
    {
        return in >> r.lx >> r.ly >> r.rx >> r.ry;
    }

    bool isin (point p)
    {
        return p.x >= lx && p.x <= rx && p.y >= ly && p.y <= ry;
    }
    
} R[25];

double dist(point a, point b)
{
    return hypot(fabs(a.x - b.x), fabs(a.y - b.y));
}

int ni, nr, did = 0;

void solve()
{
    if (!did++)
        for (int i = 0; i < ni; ++i)
            for (int j = 0; j < nr; ++j)
                if (R[j].isin(I[i]))
                    I[i].x = I[i].y = 1000;
    
    point p;
    bool flag = false;
    cin >> p;
    for (int i = nr - 1; i >= 0 && !flag; --i)
        if (flag = R[i].isin(p))
            cout << char('A' + i) << '\n';

    if (flag)
        return;
    
    double best = 1e9;
    for (int i = 0; i < ni; ++i)
        best = min(best, dist(p, I[i]));
    
    for (int i = 0; i < ni; ++i)
        if (fabs(dist(p, I[i]) - best) < eps)
            cout << setw(3) << i + 1;

    cout << '\n';
}

int main()
{
    char c;
    while (cin >> c, c != '#')
    {
        if (c == 'I')
            cin >> I[ni++];
        else if (c == 'R')
            cin >> R[nr++];
        else
            solve();
    }
}
