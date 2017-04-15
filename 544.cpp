#include <iostream>
#include <unordered_map>
#include <climits>
#include <cstring>
#include <tuple>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

typedef tuple<int, string, string> iss;
typedef vector<iss> viss;


struct UF
{
    unordered_map<string, int> r;
    unordered_map<string, string> p;
    
    void insert(string x)
    {
        if (p.find(x) != p.end())
            return;
        r.emplace(x, 0);
        p.emplace(x, x);
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
    int m, n, cs = 1;
    while (cin >> m >> n, m || n)
    {
        cout << "Scenario #" << cs++ << '\n';
        string s1, s2, a1, a2;
        int w;
        viss E;
        UF uf;
        for (int i = 0; i < n; ++i)
        {
            cin >> s1 >> s2 >> w;
            uf.insert(s1);
            uf.insert(s2);
            E.emplace_back(w, s1, s2);
        }
        int m = INT_MAX;
        sort(E.begin(), E.end(), greater<iss>());
        cin >> a1 >> a2;
        for (auto t : E)
        {
            tie(w, s1, s2) = t;
            if (!uf.s(s1, s2))
                m = min(m, w), uf.u(s1, s2);
            if (uf.s(a1, a2))
                break;
        }
        cout << m << " tons\n\n";
    }
}
