#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int best, lds[10000], cs = 0, n;
    vector<int> A;
    while (cin >> n, n != -1)
    {
        A.clear();
        A.push_back(n);
        cout << (cs? "\n" : "") << "Test #" << ++cs << ":\n";
        while (cin >> n, n != -1)
            A.push_back(n);

        n = A.size();
        best = lds[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            lds[i] = 1;
            for (int j = 0;  j < i; ++j)
                if (A[j] >= A[i])
                    lds[i] = max(lds[i], lds[j] + 1);

            best = max(best, lds[i]);
        }
        cout << "  maximum possible interceptions: " << best << '\n';
    }
}
