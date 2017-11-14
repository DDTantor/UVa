#include <iostream>

using namespace std;

string S[200];

int main()
{
    ios::sync_with_stdio(false);
    int n = 0, m = 0;
    while (getline(cin, S[n]))
        m = max(m, int(S[n++].size()));

    for (int i = 0; i < n; ++i)
        S[i] += string(m - S[i].size(), ' ');

    for (int i = 0; i < m; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
            cout << S[j][i];

        cout << '\n';
    }
}
