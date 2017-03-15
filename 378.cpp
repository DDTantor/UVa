#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t;
    cin >> t;
    cout << "INTERSECTING LINES OUTPUT\n";
    while (t--)
    {
        int x0, x1, x2, x3, y0, y1, y2, y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        //Cramerov sustav
        int D = (y0 - y1) * (x3 - x2) - (x1 - x0) * (y2 - y3);
        int D1 =((y0 - y1) * x0 + (x1 - x0) * y0) * (x3 - x2) - ((y2 - y3) * x2 + (x3 - x2) * y2) * (x1 - x0);
        int D2 = (y0 - y1) * ((y2 - y3) * x2 + (x3 - x2) * y2)  - ((y0 - y1) * x0 + (x1 - x0) * y0) * (y2 - y3);  
        
        if (D == 0 && D1 == 0 & D2 == 0)
            cout << "LINE\n";
        else if (D == 0 && (D1 != 0 || D2 != 0))
            cout << "NONE\n";
        else
            cout << "POINT " << fixed << setprecision(2) << (double)D1/D << ' ' << (double)D2/D << '\n';
            
    }
    cout << "END OF OUTPUT\n";
    
}
