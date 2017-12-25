#include <cstring>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int maxn = 1000000;

int A[maxn], n, T, res, a, p;

struct UF
{
    vi r, p;
    UF(int n) : r(n, 0), p(n, 0)
    {
        iota(p.begin(), p.end(), 0);
    }
	
    int f(int x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
	
    void u(int i, int j)
    {
        int x = f(i), y = f(j);
        if (x == y)
            return;

        if (r[x] >= r[y])
        {
            p[y] = x;
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }

    bool s(int i, int j)
    {
        return f(i) == f(j);
    }
};

inline void Update(int i, int j, UF& uf)
{
    if (A[j] == -1)
        A[j] = i;
    else if (!uf.s(i, A[j]))
        --res, uf.u(i, A[j]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; ++t)
    {
        cout << "Case " << t << ": ";
        cin >> n;
        res = n;
        memset(A, -1, sizeof A);
        UF uf(100000);
        for (int i = 0; i < n && cin >> a; ++i)
        {
            bool fl = false;
            for (int j = 2; j * j <= a; ++j)
            {
                if (!(a % j))
                {
                    fl = true;
                    Update(i, j, uf);
                    if (j * j != a)
                        Update(i, a / j, uf);
                }
            }

            if (!fl && a != 1)
                Update(i, a, uf);
        }
        
        cout << res << '\n';
    }
}
