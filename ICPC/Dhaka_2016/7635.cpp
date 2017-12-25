#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct point
{
    int x, y;
    point() {}
    friend istream& operator >>(istream& in, point& p){return in >> p.x >> p.y; }
} P[3001];

double dist(point a, point b)
{
    return hypot(a.x - b.x, a.y - b.y);
}

int main()
{
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(2);
    int n, q, r;
    while (cin >> n >> q, n || q)
    {
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        vi A(40001);
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                A[ceil(dist(P[i], P[j]))] += 2;

        for (int i = 1; i < 40001; ++i)
            A[i] += A[i - 1];
                 
        while (q--)
            cin >> r, cout << double(A[r]) / n + 1 << '\n';

        cout << '\n';
    }
}
