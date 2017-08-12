#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, A[3000];
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];
        int sum = 0;    
        for (int i = 1; i < n; ++i)
        {
            int dif = abs(A[i - 1] - A[i]);
            if (dif > n - 1 || dif < 1)
                goto stop;
            sum += dif;
        }
        if (sum != (n - 1) * n / 2)
            stop: cout << "Not jolly\n";
        else
            cout << "Jolly\n";
    }
}
