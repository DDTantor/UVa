#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n;
    string P[100];
    string S[4] = {"Happy", "birthday", "to", "you"};
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> P[i];
    
    for (int k = 0; k < ceil(n / 16.0); ++k)
        for (int i = 0; i < 16; ++i)
            cout << P[(k * 16 + i)%n] << ": " << ((i == 11)? "Rujia": S[i%4]) << '\n';
}
