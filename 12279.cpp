#include <iostream>

using namespace std;

int main()
{
    int n, c = 1;
    while (cin >> n, n)
    {
        int a, res = 0;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            if (a)
                res++;
            else
                res--;
        }
        cout << "Case " << c++ << ": " << res << '\n';
    }
}
