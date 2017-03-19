#include <iostream>

using namespace std;

int main()
{
    int t, a, b, c;
    cin >> t;
    while (cin >> a >> b >> c, t--)
        cout << (((a > 0 && b > 0 && c > 0) && (a < b + c && b < a + c && c < a + b))? "OK\n" : "Wrong!!\n");
}
