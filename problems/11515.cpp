#include <iostream>
#include <cmath>

using namespace std;

struct circle
{
    int x, y, r;
    circle() {}
    circle(int x, int y, int r) : x(x), y(y), r(r) {}
    friend istream& operator >>(istream& in, circle& c)
    {
        return in >> c.x >> c.y >> c.r;
    }
    bool intersect(circle& c)
    {
        return (x - c.x) * (x - c.x) + (y - c.y) * (y - c.y) <= (r + c.r) * (r + c.r);
    }
} C[15];

int t, n;

int val(int id, int m)
{
    if (id == n)
        return 0;

    for (int i = 0; i < n; ++i)
        if ((1 << i) & m && C[id].intersect(C[i]))
            return val(id + 1, m);

    return max(val(id + 1, m), C[id].r * C[id].r + val(id + 1, m | 1 << id));
}

int main()
{
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> C[i];

        cout << val(0, 0) << '\n';
    }
}
