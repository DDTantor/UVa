#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define eps 1e-6 

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
    friend istream& operator>>(istream& in, point& p)
    {
        return in >> p.x >> p.y;
    }
}P[101];

double cross(point a, point o, point b)
{
    return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

point LineIntersectSeg(point& p, point& q, point& A, point& B)
{
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = abs(a * p.x + b * p.y + c);
    double v = abs(a * q.x + b * q.y + c);
    return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}

vector<point> CutPolygon(point& a, point& b, vector<point>& H)
{
    vector<point> Q;
    for (int i = 0; i < H.size(); ++i)
    {
        double left1 = cross(a, H[i], b), left2 = 0;
        if (i + 1 != H.size())
            left2 = cross(a, H[i + 1], b);

        if (left1 > -eps)
            Q.push_back(H[i]);

        if (left1 * left2 < -eps)
            Q.push_back(LineIntersectSeg(H[i], H[i + 1], a, b));
    }

    if (!Q.empty() && !(Q.back().x == Q.front().x && Q.back().y == Q.front().y))
        Q.push_back(Q.front());

    return Q;
}

int main()

    ios::sync_with_stdio(false);
    int n, cs = 1;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        reverse(P, P + n);
        P[n] = P[0];
        vector<point> H(P, P + n + 1);
        for (int i = 0; i < n; ++i)
            H = CutPolygon(P[i], P[i + 1], H);
        
        cout << "Floor #" << cs++ << '\n';
        cout << "Surveillance is " << (H.empty()? "impossible.\n" : "possible.\n");
        cin.ignore();
        if (cin.peek() != 0) cout << '\n';
    }
}
