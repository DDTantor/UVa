#include <iostream>
#include <algorithm>

using namespace std;

int A[1000];

int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
            cin >> A[i];

        int cnt = 0;
        for (int i = 0; i < n - 1; ++i)
            for (int j = 1; j < n; ++j)
                if (A[j - 1] > A[j])
                    swap(A[j - 1], A[j]), ++cnt;

        cout << "Minimum exchange operations : " << cnt << '\n';
    }
}
