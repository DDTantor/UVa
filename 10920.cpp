#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll n, p;
    while (cin >> n >> p, n || p)
    {
        ll b = sqrt(p);
        if (b * b != p && (b % 2))
            b += 2;
        else if (!(b % 2))
            b++;
        
            
        ll y = b / 2, x = b / 2;
        if (b * b != 1)
        {
            ll edge = (b * b - p) / (b - 1); //na kojem od 4 ruba se nalazi
            switch(edge)
            {
                case 0:
                    y -= (b * b - p);
                    break;
                case 1:
                    y -= (b - 1);
                    x -= (b * b - p - (b - 1));
                    break;
                case 2:
                    x -= (b - 1);
                    y -= 3 * (b - 1) - (b * b - p);
                    break;
                case 3:
                    x -= 4 * (b - 1) - (b * b - p);
                    break;
            }
        }
        cout << "Line = " << y + n / 2 + 1 << ", column = " << x + n / 2 + 1 << ".\n";
    }
}
