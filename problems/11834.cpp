#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int l, c, r1, r2;

bool Check()
{
    if (c > l)
        swap(c, l);
    
    if (r2 > r1)
        swap(r1, r2);
    
    int d = r1 + r2;
    if (2 * r1 > c)
        return false;
    
    if (l >= 2 * d)
        return true;
        
    double tmp = c - d;
    tmp = sqrt(d * d - tmp * tmp);
    tmp += d;
    if (tmp <= l)
        return true;
        
    return false;
}

int main()
{
    while (cin >> l >> c >> r1 >> r2, l || c || r1 || r2)
    {
        if (Check())
            cout << "S\n";
        else
            cout << "N\n";
    }
}
