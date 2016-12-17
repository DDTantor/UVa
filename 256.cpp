#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i * i < pow(10, n); ++i)
        {
            int L = (i * i) / (int)pow(10, n / 2);
            int D = (i * i) % (int)pow(10, n / 2);
            if ((L + D) == i)
                cout << setw(n) << setfill('0') << i * i << '\n';
        }
    }
    
}
