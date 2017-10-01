#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int t, c = 1;
    long long n;
    cin >> t;
    while (cin >> n, t--)
    {
        cout << "Case " << c++ << ": ";
        if (!(n * (n - 1) % 4))
            cout << n * (n - 1) / 4 << '\n';
        else
            cout << n * (n - 1) / 2 << '/' << "2\n";
    }
      
}
