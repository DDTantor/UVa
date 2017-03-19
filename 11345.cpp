#include <iostream>

using namespace std;

int main()
{
    int t, n, c = 1;
    cin >> t;
    while (cin >> n, t--)
    {
        cout << "Case " << c++ << ": ";
        int Area, x1 , y1, x2, y2, x11, y11, x12, y12;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int i = 1; i < n; ++i)
        {
            cin >> x11 >> y11 >> x12 >> y12;
            x1 = max(x1, x11);
            y1 = max(y1, y11);
            x2 = min(x2, x12);
            y2 = min(y2, y12); 
        }
        if (x2 <= x1 || y2 <= y1)
            Area = 0;
        else    
            Area = (x2 - x1) * (y2 - y1);
            
        cout << Area << '\n';
    } 
}
