#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    int cars, cows, shows;
    while (cin >> cows >> cars >> shows)
    {
        int n = cars + cows;
        double lose = cars / (1.0 * n) * (cows - shows) / (n - shows - 1);
        lose += cows / (1.0 * n) * (cows - shows - 1) / (n - shows - 1);
        cout << fixed << setprecision(5) << 1.0 - lose << '\n';
    }
}
