#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

typedef vector<int> vi;

int main()
{
    ios::sync_with_stdio(false);
    string s;
    int n, m, d;
    while (cin >> s >> n >> m)
    {
        vi D(n * m, 1e9);
        fill(D.begin(), D.begin() + m, 0);
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < m; ++j)
                for (int k = 0; k < m && cin >> d; ++k)
                    D[m * (i + 1) + k] = min(D[m * (i + 1) + k], D[m * i + j] + d + 2);

        int res = 1e9;
        for (int i = (n - 1) * m; i < n * m; ++i)
            res = min(res, D[i]);
            
        cout << s << '\n' << res << '\n';
    }
}
