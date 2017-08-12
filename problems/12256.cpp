#include <iostream>

using namespace std;


int main()
{
    uint64_t P[61];
    P[0] = P[1] = P[2] = 1;
    for (int i = 3; i < 61; ++i)
        P[i] = P[i - 1] + P[i - 2] + P[i - 3];
    
    int c = 1, n;
    while (cin >> n, n)
        cout << "Case " << c++ << ": " << P[n - 1] << '\n';
}
