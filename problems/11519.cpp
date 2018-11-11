#include <iostream>
#include <cmath>

using namespace std;

#define eps 1e-2

string C[1000];
int id, num[1000], n, t;

int solve()
{
    int upper = (C[id] == "lt" || C[id] == "rt" ? 360 : 1);
    
    for (int k = 0; k < upper; ++k)
    {
        double x = 0, y = 0, angle = 0;
        num[id] = k;

        for (int i = 0; i < n; ++i)
        {
            if (C[i] == "fd" || C[i] == "bk")
            {
                int sign = (C[i] == "fd"? 1 : -1);
                x += cos(angle / 180 * M_PI) * sign * num[i];
                y += sin(angle / 180 * M_PI) * sign * num[i];
            }
            else
            {
                int sign = (C[i] == "lt"? 1 : -1);
                angle += num[i] * sign;
            }
        }

        
        if (upper == 1)
            return sqrt(x * x + y * y) + eps;
        
        if (abs(x) < eps && abs(y) < eps)
            return k;
    }
    
    return 0;
}

int main()
{
    cin >> t;
    while (cin >> n, t--)
    {
        string a;
        for (int i = 0; i < n; ++i)
        {
            cin >> C[i] >> a;
            if (a == "?")
                id = i;
            else
                num[i] = stoi(a);
        }

        cout << solve() << '\n';
    }
}
