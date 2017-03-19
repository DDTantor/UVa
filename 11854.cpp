#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c;
    while (cin >> a >> b >> c, a)
    {
        if (a * a == b * b + c * c ||
            b * b == a * a + c * c ||
            c * c == b * b + a * a)
            cout << "right\n";
        else
            cout << "wrong\n";
     }   
            
    
}
