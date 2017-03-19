#include <iostream>
#include <cmath>
#include <iomanip>
#include <functional>
#include <algorithm>

using namespace std;


double Area(double a, double b, double c)
{
    if (a > c + b || b > a + c || c > a + b)
        return 0;
        
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main()
{
    int n, t;
    double S[10000];
    cin >> t;
    while (cin >> n, t--)
    {
        for (int i = 0; i < n; ++i)
            cin >> S[i];
        
        sort(S, S + n);    
        double m = 0;
        for (int i = n - 1; i >= 2; --i)
            m = max(m, Area(S[i], S[i - 1], S[i - 2]));
        
        cout << fixed << setprecision(2) << m << endl;
    }
    
}
