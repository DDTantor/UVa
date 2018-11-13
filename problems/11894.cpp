#include <iostream>
#include <tuple>
#include <cstring>
#include <algorithm> 
using namespace std;

const int maxn = 100000;

struct point
{
    int x, y;
    point(){}
    point(int x, int y) : x(x), y(y) {}
    bool operator<(const point& p) {return tie(x, y) < tie(p.x, p.y);}
    friend istream& operator>>(istream& in, point& p) {return in >> p.x >> p.y;}
    
}P[maxn], Q[maxn];

int n, t;

string solve()
{
    sort(Q, Q + n);
    for (int k = 0; k < 4; ++k)
    {
        sort(P, P + n);
        int cnt = 1;
        int transx = Q[0].x - P[0].x;
        int transy = Q[0].y - P[0].y;
        
        for (int i = 1; i < n; ++i)
            cnt += (Q[i].x == P[i].x + transx && Q[i].y == P[i].y + transy);

        if (cnt == n)
            return "MATCHED";

        for (int i = 0; i < n; ++i)
            P[i] = point(-P[i].y, P[i].x);
    }
    
    return "NOT MATCHED";
}
      
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> Q[i];
            
        for (int i = 0; i < n; ++i)
            cin >> P[i];

        cout << solve() << '\n';
    }
}
