#include <iostream>

using namespace std;

int main()
{
    int h, p, d;
    double c;
    while (cin >> h >> p >> d >> c, h)
    {
        double l = p * c / 100.0;
        int dan = 0;
        double tren = 0;
        do
        {
            dan++;
            double fat = l * (dan - 1);
            tren += ((fat > p)? 0 : p - fat);
            if (tren > h)
                break;
            tren -= d;
        }while(tren >= 0 && tren < h);
        if (tren <= 0)
            cout << "failure ";
        else
            cout << "success ";
        cout << "on day " << dan << '\n';
        
    }
    
}
