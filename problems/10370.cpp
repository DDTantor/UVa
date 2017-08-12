#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int t, n, A[1000];
    cin >> t;
    cout << fixed << setprecision(3);
    while (t--)
    {
        cin >> n;
        double av = 0;
        for (int i = 0; i < n; ++i)
            cin >> A[i], av += A[i];
            
        av /= (double)n;
        int ab = 0;
        for (int i = 0; i < n; ++i)
            if (A[i] > av)
                ab++;
                
        cout << (ab * 100.0) / n << "%\n";
    }
}
