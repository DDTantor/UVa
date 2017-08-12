#include <iostream>
#include <vector>

using namespace std;

struct point
{
    int x, y;
    point () {}
    point (int x, int y) : x(x), y(y) {}
    point operator -(const point& other) { return point(x - other.x, y - other.y);}
    friend istream& operator >> (istream& in, point& a){return in >> a.x >> a.y;}
    
}P[200000];

int Sign(const point& a)
{
    return abs(a.x) / a.x == abs(a.y) / a.y;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> P[i];
            
        int S = 0, O = 0;
        for (int i = 0; i < n; ++i)
        {
            point A = P[i] - P[(n - 1) / 2];
            if (A.x != 0 && A.y != 0)
                (Sign(A)? S : O) += 1;
        }
            
        cout << S << ' ' << O << '\n';
    }
    
}
