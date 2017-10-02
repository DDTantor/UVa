#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;

int main()
{
    long long I;
    while (cin >> I, I)
    {
        cout << "The parity of ";
        long long tmp = I;
        string s;
        while (tmp)
            s = to_string(tmp % 2) + s, tmp /= 2;
        
        cout << s  << " is " << __builtin_popcount(I) << " (mod 2).\n";
    }
}
