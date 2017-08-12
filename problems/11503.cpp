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
        {
            cout << size[x] << '\n';
            return;
        }
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
        cout << size[f(i)] << '\n';
    }
    
    bool s(string i, string j)
    {
        return f(i) == f(j);
    }
};


int main()
{
    int t, n;
    cin >> t;
    while (cin >> n, t--)
    {
        string s1, s2;
        UF uf;
        for (int i = 0; i < n; ++i)
        {
            cin >> s1 >> s2;
            if (uf.p.find(s1) == uf.p.end())
                uf.insert(s1);
            if (uf.p.find(s2) == uf.p.end())
                uf.insert(s2);
            uf.u(s1, s2);
        }
    }
}
