#include <iostream>

using namespace std;

struct point
{
    double x, y;
    point (){}
    point (double x, double y) : x(x), y(y) {}
};

struct segment
{
    point a, b;
    friend istream& operator >> (istream& in, segment& s)
    {
        return in >> s.a.x >> s.a.y >> s.b.x >> s.b.y;
    } 
    
}S[100];

double cross(point a, point b){return a.x * b.y - a.y * b.x;} 
double direction(point pi, point pj, point pk){ return cross(point(pk.x - pi.x, pk.y - pi.y), point(pj.x - pi.x, pj.y - pi.y));}

bool OnSegment(point pi, point pj, point pk)
{
    if (min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x)
    && min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y))
        return true;
        
    return false;
}

bool SegmentsIntersect(const segment& l1, const segment& l2)
{
    double d1 = direction(l2.a, l2.b, l1.a);
    double d2 = direction(l2.a, l2.b, l1.b);
    double d3 = direction(l1.a, l1.b, l2.a);
    double d4 = direction(l1.a, l1.b, l2.b);
    
    if (((d1 < 0 && d2 > 0) || (d1 > 0 && d2 < 0))
     && ((d3 < 0 && d4 > 0) || (d3 > 0 && d4 < 0)))
        return true;
        
    else if (d1 == 0 && OnSegment(l2.a, l2.b, l1.a))
        return true;
    else if (d2 == 0 && OnSegment(l2.a, l2.b, l1.b))
        return true;
    else if (d3 == 0 && OnSegment(l1.a, l1.b, l2.a))
        return true;
    else if (d4 == 0 && OnSegment(l1.a, l1.b, l2.b))
        return true;
        
    return false;
}

int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> S[i];
        
        int T = n;
        for (int i = 0; i < n; ++i)
        {
            bool flag = false;
            for (int j = 0; j < n; ++j)
                if (i != j)
                    flag |= SegmentsIntersect(S[i], S[j]);
                
            T -= flag;
        }
        cout << T << '\n';
    }
}
