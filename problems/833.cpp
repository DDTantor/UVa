#include <iostream>
#include <algorithm>

using namespace std;

struct segment{ int x1, y1, x2, y2, minx, maxx;
    void Set() 
    {
        if (y1 > y2)
            swap(y1, y2), swap(x1, x2);
        maxx = max(x1, x2);
        minx = min(x1, x2);
    }
    bool operator < (const segment &other) const {return y2 > other.y2;}
    
    friend istream& operator >>(istream& in, segment& s)
    {
        return in >> s.x1 >> s.y1 >> s.x2 >> s.y2;
    }
    
}S[100];

int n;

int Solve(int x, int y)
{
    for (int i = 0; i < n; ++i)
    {
        if (y > S[i].y1 && x >= S[i].minx && x <= S[i].maxx) 
            x = S[i].x1, y = S[i].y1;
    }
    return x;
}

int main()
{
    int n, xA, yA, xB, yB, t, p, x, y;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> S[i];
            S[i].Set();
        }
        
        sort(S, S + n);
        cin >> p;
        
        while (p--)
        {
            cin >> x >> y;
            for (int i = 0; i < n; ++i)
                if (y > S[i].y1 && x >= S[i].minx && x <= S[i].maxx)
                    y = S[i].y1, x = S[i].x1;
            
            cout << x << '\n';
        }
        if (t)
            cout << '\n';
    }
    
}
