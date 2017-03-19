#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x11, y11, x12, y12, x21, y21, x22, y22;
        
        cin >> x11 >> y11 >> x21 >> y21 >> x12 >> y12 >> x22 >> y22;
        
        int x1 = max(x11, x12);
        int y1 = max(y11, y12);
        int x2 = min(x21, x22);
        int y2 = min(y21, y22);
        if (x1 < x2 && y1 < y2)
            cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
        else
            cout << "No Overlap\n";
            
        if (t) 
            cout << '\n';
    }
    
}
