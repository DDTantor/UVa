#include <iostream>

using namespace std;

int main()
{
    int p, a, b, c;
    while (scanf("%d %d %d %d", &p, &a, &b, &c), (p || a || b || c))
        cout << (120 + ((p > a)? p - a : p - a + 40)
                     + ((a > b)? b - a + 40 : b - a) 
                     + ((b > c)? b - c : b - c + 40)) * 9 << '\n';

}
