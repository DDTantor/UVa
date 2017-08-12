#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int main()
{
    int n, m, cs = 0, c, b, T[20], s, Q[20], R[10];
    bool C[10];
    vvi same;
    while (cin >> n >> b, n || b)
    {
        for (int i = 0; i < n; ++i)
            cin >> T[i];

        same.assign(n, vi());
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> c;
            for (int j = 0; j < c; ++j)
                cin >> Q[j];

            cin >> s;
            R[i] = s;
            for (int j = 0; j < c; ++j)
            {
                same[Q[j] - 1].push_back(i);
                T[Q[j] - 1] -= s;
            }
        }

        int best, M = 0;
        for (int i = 0; i < (1 << n); ++i)
        {
            if (__builtin_popcount(i) == b)
            {
                memset(C, false, sizeof(C));
                int sum = 0;
                for (int j = 0; j < n; ++j)
                {
                    if (i & (1 << j))
                    {
                        sum += T[j];
                        for (int a : same[j])
                            if (!C[a])
                                sum += R[a], C[a] = true;
                    }
                }
                if (sum > M)
                    M = sum, best = i;
            }
        }
        cout << "Case Number  " << ++cs << '\n';
        cout << "Number of Customers: " << M << '\n';
        cout << "Locations recommended:";
        for (int j = 0; j < n; ++j)
            if (best & (1 << j))
                cout << ' ' << j + 1;
        
        cout << "\n\n";
    }
}
