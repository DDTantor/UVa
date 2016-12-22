#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<int> vi;
int main()
{
    int n, c = 1;
    while (cin >> n, n != -1)
    {
        cout << "Case " << c++ << ": ";
        vi Res;
        double L[6];
        int G[6], Y[6], R[6];
        
        for (int i = 0; i < n; ++i)
            cin >> L[i] >> G[i] >> Y[i] >> R[i];
        
        for (int v = 30; v <= 60; ++v)
        {
            bool flag = true;
            for (int i = 0; i < n; ++i)
                if (fmod(L[i] * 3600.0 / v, G[i] + Y[i] + R[i]) > Y[i] + G[i])
                    flag = false;
            if (flag)
                Res.push_back(v);
        }
        Res.push_back(0);
        if (Res.size() > 1)
        {
            int l, h;
            l = h = Res[0];
            for (int i = 1; i < Res.size(); ++i)
            {
                if (h + 1 != Res[i])
                {
                    if (h == l)
                        cout << l;
                    else
                        cout << l << '-' << h;
                    if (i != Res.size() - 1)
                        cout << ", ";
                    l = h = Res[i];
                }
                else
                    h++;
            }
        }
        else
            cout << "No acceptable speeds.";
        cout << '\n';
    }
}
