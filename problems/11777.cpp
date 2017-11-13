#include <iostream>

using namespace std;

string G = "FDCBAA";
int A[7];

int main()
{
    ios::sync_with_stdio(false);
    int t, cs = 0;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < 7; ++i)
            cin >> A[i];

        int res = A[0] + A[1] + A[2] + A[3];
        res += (A[4] + A[5] + A[6] - min(A[4], min(A[5], A[6]))) / 2;
        cout << "Case " << ++cs << ": " << G[max(0, res / 10 - 5)] << endl;
    }
}
