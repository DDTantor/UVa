#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int cs = 1, n;
string A[10], B[10], tmp[10];

void rotate()
{
    copy(A, A + 10, tmp);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            tmp[i][j] = A[n - 1 - j][i];

    copy(tmp, tmp + 10, A);
}

void reflect()
{
    for (int i = 0; 2 * i < n; ++i)
        for (int j = 0; j < n; ++j)
            swap(A[i][j], A[n - 1 - i][j]);
}

bool cmp()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (A[i][j] != B[i][j])
                return false;

    return true;
}

string solve()
{
    if (cmp())
        return "preserved.";

    string t = "";
    for (int i = 0; i < 2; t = "reflected vertically and ", ++i)
    {
        for (int k = 1; k <= 4; ++k)
        {
            rotate();
            if (cmp())
                return t + "rotated " + to_string(k * 90) + " degrees.";
        }

        reflect();
        if (cmp())
            return "reflected vertically.";
    }

    return "improperly transformed.";
}

int main()
{
    while (cin >> n)
    {
        cout << "Pattern " << cs++ << " was ";
        for (int i = 0; i < n; ++i)
            cin >> A[i] >> B[i];
        
        cout << solve() << '\n';
    }
}
