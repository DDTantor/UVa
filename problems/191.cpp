#include <iostream>
#include <cmath>
#include <vector>

using namespace std;


struct vec { int x = 0, y = 0;
    vec (int x, int y) : x(x), y(y) {}
};

int cross(vec a, vec b) { return a.x * b.y - a.y * b.x;}
int direction(vec pi, vec pj, vec pk) { return cross(vec(pk.x - pi.x, pk.y - pi.y), vec(pj.x - pi.x, pj.y - pi.y));}

bool OnSegment(vec pi, vec pj, vec pk)
{
    if (min(pi.x, pj.x) <= pk.x && pk.x <= max(pi.x, pj.x)
    && min(pi.y, pj.y) <= pk.y && pk.y <= max(pi.y, pj.y))
        return true;
        
    return false;
}

bool SegmentsIntersect(vec p1, vec p2, vec p3, vec p4)
{
    int d1 = direction(p3, p4, p1);
    int d2 = direction(p3, p4, p2);
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);
    
    if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) 
        && ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0)))
        return true;
    else if (d1 == 0 && OnSegment(p3, p4, p1))
        return true;
    else if (d2 == 0 && OnSegment(p3, p4, p2))
        return true;
    else if (d3 == 0 && OnSegment(p1, p2, p3))
        return true;
    else if (d4 == 0 && OnSegment(p1, p2, p4))
        return true;
        
    return false;
}

bool InsidePolygon(vec p, vec A1, vec A2, vec A3, vec A4)
{
    return (p.x >= A1.x && p.x <= A3.x && p.y >= A1.y && p.y <= A3.y);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        vec p(ax, ay), r(bx, by);
        
        cin >> ax >> ay >> bx >> by;
        vec A1(min(ax, bx), min(ay, by)); 
        vec A2(max(ax, bx), min(ay, by)); 
        vec A3(max(ax, bx), max(ay, by)); 
        vec A4(min(ax, bx), max(ay, by));
        
        bool is = false;
        
        is |= InsidePolygon(p, A1, A2, A3, A4);
        is |= InsidePolygon(r, A1, A2, A3, A4);
        
        is |= (SegmentsIntersect(A1, A2, p, r) ||
                   SegmentsIntersect(A2, A3, p, r) ||
                   SegmentsIntersect(A3, A4, p, r) ||
                   SegmentsIntersect(A4, A1, p, r));
        
        if (is)
            cout << "T\n";
        else
            cout << "F\n";
    }
}
