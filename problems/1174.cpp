#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#include <map>

using namespace std;

typedef tuple<int, string, string> iss;
typedef vector<iss> viss;

struct UF
{
    map<string, int> r;
    map<string, string> p;
    
    void insert(string x)
    {
        if (p.find(x) != p.end())
            return;
        r[x] = 0;
        p[x] = x;
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
            if (r[x] == r[y])
                r[x]++;
        }
        else
            p[x] = y;
    }
    
    bool s(string i, string j)
    {
        return f(i) == f(j);
    }
};

int main()
{
    int t, m, n;
    cin >> t;
    while (cin >> m >> n, t--)
    {
        viss E;
        string s1, s2;
        int w;
        for (int i = 0; i < n; ++i)
            cin >> s1 >> s2 >> w, E.emplace_back(w, s1, s2);
        sort(E.begin(), E.end());
        UF uf;
        int sum = 0;
        for (auto t : E)
        {
            tie(w, s1, s2) = t;
            uf.insert(s1);
            uf.insert(s2);
            if (!uf.s(s1, s2))
                sum += w, uf.u(s1, s2);
        }
        cout << sum << '\n';
        if (t)
            cout << '\n';
    }
}
