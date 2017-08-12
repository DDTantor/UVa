#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef tuple<int, string, string> iss;
typedef vector<iss> viss;

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
    }
    
    bool s(string i, string j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int n, m;
    while (cin >> n >> m, n || m)
    {
        UF uf;
        string s1, s2;
        int w;
        for (int i = 0; i < n; ++i)
            cin >> s1, uf.insert(s1);
        viss E;
        for (int i = 0; i < m; ++i)    
            cin >> s1 >> s2 >> w, E.emplace_back(w, s1, s2);
        sort(E.begin(), E.end());
        int sum = 0;
        for (auto t : E)
        {
            tie(w, s1, s2) = t;
            if (!uf.s(s1, s2))
                sum += w, uf.u(s1, s2);
        }
        cin >> s1;
        if (uf.size[uf.f(s1)] < n)
            cout << "Impossible\n";
        else
            cout << sum << '\n';
    }
}
