#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;  
        int res = 315 * abs(n) + ((n < 0)? -36962 : 36962);
        cout << abs((res / 10) % 10) << endl;
    }
}
