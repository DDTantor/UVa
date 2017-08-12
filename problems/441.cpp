#include <iostream>

using namespace std;

int main()
{
    int k, A[13];
    while (cin >> k, k)
    {
        for (int i = 0; i < k; ++i)
            cin >> A[i];

        for (int i1 = 0; i1 < k -5; ++i1)
            for (int i2 = i1 + 1; i2 < k - 4; ++i2)
                for (int i3 = i2 + 1; i3 < k - 3; ++i3)
                    for (int i4 = i3 + 1; i4 < k - 2; ++i4)
                        for (int i5 = i4 + 1; i5 < k - 1; ++i5)
                            for (int i6 = i5 + 1; i6 < k; ++i6)
                                cout << A[i1] << ' ' << A[i2] << ' ' << A[i3] << ' ' << A[i4] << ' ' << A[i5] << ' ' << A[i6] << '\n';

        cin.ignore();
        if (cin.peek() != '0')
            cout << '\n';
    }
}
