#include <iostream>
#include <algorithm>

using namespace std;

    
int main()
{
    int A[110000] = {0};
    for (int i = 1; i < 100000; ++i)
    {
        int sum, temp;
        sum = temp = i;
        while (temp)
        {
            sum += (temp % 10);
            temp /= 10;
        }
        A[sum] = (A[sum])? min(A[sum], i): i;
    }

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << A[n] << '\n';
    }
}
