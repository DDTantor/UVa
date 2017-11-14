#include <iostream>
#include <iomanip>

using namespace std;

long long dp[30006], cVal[11] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

int main()
{
    ios::sync_with_stdio(false);
    dp[0] = 1;
    for (int i = 0; i < 11; ++i)
        for (int j = cVal[i]; j < 30001; ++j)
            dp[j] += dp[j - cVal[i]];
    
    double a;
    while (cin >> a, a)
        cout << setw(6) << fixed << setprecision(2) << a << setw(17) << dp[int(100 * (a + 0.001))] << '\n';
}
