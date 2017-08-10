#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int A[100000], B[100000], Bi[100000], pred[100000];

void printout(int pos)
{
    if (pos != -1)
        printout(pred[pos]), cout << A[pos] << '\n';
}

int main()
{
    int a, n, best = 0, pos = 0;
    while (cin >> a) A[n++] = a;
    for (int i = 0; i < n; ++i)
    {
        int t = lower_bound(B, B + best, A[i]) - B;
        B[t] = A[i];
        Bi[t] = i;
        pred[i] = t > 0? Bi[t - 1] : -1;
        if (t == best)
            best++, pos = i;
    }
    cout << best << "\n-\n";
    printout(pos);
}
