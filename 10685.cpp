#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct UF
{
    int m = 1;
    map<string, int> r, size;
    map<string, string> p;
    
    void insert(string x)
    {
        r[x] = 0;
        p[x] = x;
        size[x] = 1;
    }
    
    string f(string x)
    {
        return (p[x] == x ? x : p[x] = f(p[x]));
    }
    
    void u(string i, string j)
    {
        string x = f(i), y = f(j);
        if (x == y)
            return;
        if (r[x] >= r[y])
        {
            p[y] = x;
            size[x] += size[y];
            if (r[x] == r[y])
                r[x]++;
        }
        else
        {
            p[x] = y;
            size[y] += size[x];
        }
        m = max(m, max(size[y], size[x]));
    }
    
    bool s(string i, string j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int m, n;
    while (cin >> m >> n, m || n)
    {
        UF uf;
        string s1, s2;
        for (int i = 0; i < m; ++i)
            cin >> s1, uf.insert(s1);
        for (int i = 0; i < n; ++i)
            cin >> s1 >> s2, uf.u(s1, s2);
        cout << uf.m << '\n';
    }
}
