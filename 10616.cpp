#include <iostream>
#include <cstring>

using namespace std;

int n, q, cs = 1, cnt;
int table[11][200][201];
long long W[200], d, m;

int solve(int sz, int sum, int ind)
{
    
    if (sz == m)
        return (sum == 0);

    if (ind >= n)
        return 0;
    
    if (table[sz][sum][ind])
        return table[sz][sum][ind];
    
    return table[sz][sum][ind] =
        solve(sz, sum, ind + 1) + solve(sz + 1, (sum + W[ind]) % d, ind + 1);
}


int main()
{
    while (cin >> n >> q, n || q)
    {
        cout << "SET " << cs++ << ":\n";
        for (int i = 0; i < n; ++i)
            cin >> W[i];
        
        for (int i = 1; i <= q; ++i)
        {
            memset(table, 0, sizeof(table));
            cout << "QUERY " << i << ": ";
            cin >> d >> m;
            cout << solve(0, 0, 0) << endl;
        }

    }
}
