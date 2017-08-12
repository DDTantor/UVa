#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ll s, d;
    while (cin >> s >> d)
        cout << s - 1 + (int)ceil((1 - 2 * s + sqrt((2 * s - 1) * (2 * s - 1) + 8 * d)) / 2) << '\n' ;
}
