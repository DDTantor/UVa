#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t, n;
    double A[3001];
    cin >> t;
    cout << fixed << setprecision(2);
    while (cin >> n, t--)
    {
        double a, b, sum = 0;
        cin >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            double c;
            cin >> c;
            sum += 2 * (n - i) * c;
        }   
        cout << (n * a + b - sum) / (n + 1) << '\n';
        if (t) 
            cout << '\n';
    }
}
