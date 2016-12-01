#include <iostream>
#include <string>
#include <bitset>
#include <sstream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        stringstream s;
        s << hex << to_string(n);
        bitset<32> b1(n);
        s >> n;
        bitset<32> b2(n);
        cout << b1.count() << ' ';
        cout << b2.count() << '\n';
    }
}
