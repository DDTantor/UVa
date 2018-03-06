#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>

using namespace std;

struct vedge
{
    double x;
    int id;
    char c;
    vedge() {}
    bool operator <(const vedge& e) const {return x < e.x;}
} VE[200];

struct hedge
{
    double y;
    int id;
    char c;
    hedge() {}
    bool operator <(const hedge& e) const {return y < e.y;}
} HE[200];

void S(double x, double y, double r, int i, int n)
{
    VE[i].id = VE[i + n].id = HE[i].id = HE[i + n].id = i;
    VE[i + n].x = x + r;
    VE[i].x = x - r;
    HE[i + n].y = y + r;
    HE[i].y = y - r;
    VE[i].c = 'l', VE[i + n].c = 'r', HE[i].c = 'u', HE[i + n].c = 'd';
}

void erase(set<hedge>& box, int id)
{
    for (auto it = box.begin(); it != box.end();)
    {
        if (it->id == id)
            it = box.erase(it);
        else
            ++it;
    }
}
           

int main()
{
    int n, cs = 0;
    while (cin >> n, n)
    {
        cout << ++cs << ' ';
        double x, y, r;
        for (int i = 0; i < n; ++i)
            cin >> x >> y >> r, S(x, y, r, i, n);

        sort(VE, VE + 2 * n);
        set<hedge> box;
        double prevx, res = 0;
        for (int i = 0; i < 2 * n; ++i)
        {
            double x = VE[i].x, len = 0, prevy = box.begin()->y;
            int cnt = 0;
            for (hedge it : box)
            {
                double y = it.y;
                len += (cnt && 1) * (y - prevy);
                cnt += (it.c == 'u'? 1 : -1);
                prevy = y;
            }
            
            res += len * (x - prevx);
            prevx = x;
            if (VE[i].c == 'l')
                box.insert(HE[VE[i].id]), box.insert(HE[VE[i].id + n]);
            else
                erase(box, VE[i].id);
        }

        cout << fixed << setprecision(2) << res << '\n';
    }
}
