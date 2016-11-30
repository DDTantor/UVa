#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n, A[50], s = 1;
    while (cin >> n, n)
    {
        cout << "Set #" << s++ << '\n';
        cout << "The minimum number of moves is ";
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> A[i];
            sum += A[i];
        }
        sum /= n;
        int dif = 0;
        for (int i = 0; i < n; ++i)
            dif += abs(sum - A[i]);
            
        cout << dif / 2 << ".\n\n";
    }
}
