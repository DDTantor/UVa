#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define eps 1e-6

struct point
{
    int x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator>>(istream& in, point& p)
    {
        in >> p.x >> p.y;
    }   
}P[700], f;

int dist(point a, point b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cmp(point a, point b)
{
    if (cross(a, f, b) == 0)
        return dist(f, a) < dist(f, b);

    return cross(a, f, b) < 0;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        int n = 0, best = 2;
        while (cin.peek() != '\n' && !cin.eof())
            cin >> P[n++], cin.ignore();

        for (int i = 0; i < n; ++i)
        {
            f = P[i];
            sort(P, P + n, cmp);
            for (int i = 2, cnt = 2; i < n; ++i)
            {
                cnt = (cross(f, P[i - 1], P[i]) == 0? cnt + 1 : 2);
                best = max(cnt, best);
            }
        }
        
        cout << best << '\n';
        if (t)
            cout << '\n';
        cin.ignore();
    }
}
