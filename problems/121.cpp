#include <iostream>
#include <cmath>

using namespace std;

int skew(double a, double b)
{
    if (b < 1)
        return 0;
    int cols = (int) a;
    int rows = 2 * (b - 1) / sqrt(3) + 1;
    return (int)((rows - rows/2) * (int)a + rows / 2 * (int)(a - 0.5));
}

int main()
{
    double a, b;
    while (cin >> a >> b)
    {
        int G = (int)a * (int)b;
        int S = max(skew(a, b), skew(b, a));
        cout << max(G, S) << ((G >= S)? " grid\n" : " skew\n");
    }
    
}
