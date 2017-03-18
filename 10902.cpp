#include <iostream>

using namespace std;

struct point
{
    double x, y;
    point() {}
    point(double x, double y): x(x), y(y) {}
};

struct line
{
    point a, b;
    friend istream& operator >>(istream& in, line& l)
    {
        return in >> l.a.x >> l.a.y >> l.b.x >> l.b.y;
    }
    
}L[100000];

double cross(point a, point b){return a.x * b.y - a.y * b.x;} 
double direction(point pi, point pj, point pk){ return cross(point(pk.x - pi.x, pk.y - pi.y), point(pj.x - pi.x, pj.y - pi.y));}

bool OnSegment(point pi, point pj, point pk)
{
    if (min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x)
    && min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y))
        return true;
        
    return false;
}

bool SegmentsIntersect(const line& l1, const line& l2)
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
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; ++i)
            cin >> L[i];
        
        cout << "Top sticks: ";
        for (int i = 0; i < n; ++i)
        {
            bool flag = false;
            for (int j = i + 1; j < n && !flag; ++j)
                flag |= SegmentsIntersect(L[i], L[j]);
                    
            if (!flag)
            {
                cout << i + 1;
                if (i != n - 1)
                    cout << ", ";
                else
                    cout << ".\n";
            }
        }
    }
}
