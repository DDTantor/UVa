#include <iostream>
#include <vector>

using namespace std;

typedef vector<short> vi;

const int maxn = int(1e4);
vi A[2];

int main()
{
    ios::sync_with_stdio(false);
    int N, id = 0;
    for (int i = 1; i <= maxn; ++i, id = (id + 1) % 2)
        for (int j = 1; j <= i; ++j)
            A[id].push_back(i - j + 1), A[(id + 1) % 2].push_back(j);

    while (cin >> N)
        cout << "TERM " << N << " IS " << A[0][N - 1] << '/' << A[1][N - 1] << '\n';
}
