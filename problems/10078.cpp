#include <iostream>
#include <cmath>

using namespace std;

struct point
{
    int x, y;
    point(){}
    friend istream& operator>>(istream& in, point& p)
    {
        in >> p.x >> p.y;
    }
} P[52];

int cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool IsConvex(int n)
{
    bool isLeft = signbit(cross(P[0], P[1], P[2]));
    for (int i = 1; i < n; ++i)
        if (signbit(cross(P[i], P[i + 1], P[i + 2])) != isLeft)
            return false;
    
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        P[n] = P[0], P[n + 1] = P[1];
        cout << (IsConvex(n)? "No\n" : "Yes\n");
    }
}
