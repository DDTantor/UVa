#include <iostream>

using namespace std;

typedef long long ll;

int cs = 0, A[18], n;

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        ll b = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                ll tmp = 1;
                for (int k = i; k < j; ++k)
                    tmp *= A[k];

                b = max(b, tmp);
            }
        }

        cout << "Case #" << ++cs << ": The maximum product is " << b << ".\n\n";
    }
}
