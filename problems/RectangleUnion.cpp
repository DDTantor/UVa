#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

struct event
{
    int ind, type;
    event(){}
    event(int ind, int type) : ind(ind), type(type) {}
} Eh[200], Ev[200];

struct point
{
    double x, y;
    point(){}
    point(double x, double y) : x(x), y(y) {}
} rec[100][2];

bool cmpx(event a, event b) {return rec[a.ind][a.type].x < rec[b.ind][b.type].x;}
bool cmpy(event a, event b) {return rec[a.ind][a.type].y < rec[b.ind][b.type].y;}

double UnionArea(int e)
{
    double res = 0;
    bool In[200] = {false};
    sort(Eh, Eh + e, cmpy);
    sort(Ev, Ev + e, cmpx);
    In[Ev[0].ind] = 1;
    for (int i = 1; i < e; ++i) 
    { 
        event c = Ev[i];
        int cnt = 0;
        double Dx = rec[c.ind][c.type].x - rec[Ev[i - 1].ind][Ev[i - 1].type].x;
        double len = 0, prevy;
        
        if (Dx != 0)
        {
            for (int j = 0; j < e; ++j)
            {
                if (In[Eh[j].ind])
                {
                    double y = rec[Eh[j].ind][Eh[j].type].y;
                    len += (cnt > 0? y - prevy: 0), cnt += (Eh[j].type == 0? 1 : -1), prevy = y; 
                }
                    
            }

            res += len * Dx;
        }
        
        In[c.ind] = (c.type == 0);
    }
    
    return res;
}

int main()
{
    int n, c = 1;
    while (cin >> n, n)
    {
        double x, y, r;
        for (int i = 0; i < n; ++i)
        {
            cin >> x >> y >> r;
            rec[i][0] = point(x - r, y - r), rec[i][1] = point(x + r, y + r);
            Eh[i] = event(i, 0), Eh[i + n] = event(i, 1);
            Ev[i] = event(i, 0), Ev[i + n] = event(i, 1);
        }

        cout << fixed << setprecision(2) << c++ << ' ' << UnionArea(2 * n) << '\n';
    }
}
