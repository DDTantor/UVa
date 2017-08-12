#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "PERFECTION OUTPUT\n";
    int n;
    while (cin >> n, n)
    {
        cout << setw(5) << n;
        int sum = 0;
        for (int i = 1; i < n; ++i)
            if (!(n % i))
                sum += i;
        if (sum == n)
            cout << "  PERFECT\n";
        else if (sum < n)
            cout << "  DEFICIENT\n";
        else
            cout << "  ABUNDANT\n";
    }
    cout << "END OF OUTPUT\n";
}
