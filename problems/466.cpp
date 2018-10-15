#include <iostream>
#include <algorithm>
#include <cstring>
#include <array>

using namespace std;

int cs = 1, n;
array<array<char, 10>, 10> A, B, tmp;


void rotate()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            tmp[i][j] = A[n - 1 - j][i];

    A = tmp;
}

void reflect()
{
    for (int i = 0; 2 * i < n; ++i)
        for (int j = 0; j < n; ++j)
            swap(A[i][j], A[n - 1 - i][j]);
}

string solve()
{
    if (A == B)
        return "preserved.";

    string t = "";
    for (int i = 0; i < 2; t = "reflected vertically and ", ++i)
    {
        for (int k = 1; k <= 4; ++k)
        {
            rotate();
            if (A == B)
                return t + "rotated " + to_string(k * 90) + " degrees.";
        }

        reflect();
        if (A == B)
            return "reflected vertically.";
    }

    return "improperly transformed.";
}

int main()
{
    while (cin >> n)
    {
        for (int i = 0; i < 10; ++i)
            for (int j = 0; j < 10; ++j)
                A[i][j] = B[i][j] = tmp[i][j] = ' ';
        
        cout << "Pattern " << cs++ << " was ";
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                cin >> A[i][j];

            for (int j = 0; j < n; ++j)
                cin >> B[i][j];
        }
        
        cout << solve() << '\n';
    }
}
