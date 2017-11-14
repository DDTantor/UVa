#include <iostream>
#include <iomanip>

using namespace std;

double A[1000];

int main()
{
    int n;
    while (cin >> n, n)
    {
        double total = 0, res1 = 0, res2 = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            total += A[i];
        }

        total /= n;
        for (int i = 0; i < n; ++i)
        {
            double dif = (double)(long)((A[i] - total) * 100.0) / 100.0;
            if (dif > 0)
                res1 += dif;
            else
                res2 -= dif;
        }
        
        cout << fixed << setprecision(2) << '$' << max(res1, res2) << '\n';
    }
}
    
