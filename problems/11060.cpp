#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <utility>

using namespace std;

typedef vector<string> vs;
typedef pair<int, string> is;
typedef vector<is> vis;

int main()
{
    int n, m, cs = 1;
    while (cin >> n)
    {
        cout << "Case #" << cs++ << ": Dilbert should drink beverages in this order:";
        string s1, s2;
        unordered_map<string, int> IND, IN;
        
        for (int i = 0; i < n; ++i)
        {
            cin >> s1;
            IND[s1] = 0;
            IN[s1] = i;
        }
            
        cin >> m;
        unordered_map<string, vs> G;
        for (int i = 0; i < m; ++i)
        {
            cin >> s1 >> s2;
            G[s1].push_back(s2);
            IND[s2]++;
        }
        priority_queue<is, vis, greater<is> > Q;
        for (auto e : IND)
            if (!e.second)
                Q.emplace(IN[e.first], e.first);
                
        while (!Q.empty())
        {
            s1 = Q.top().second; Q.pop();
            cout << ' ' << s1;
            for (string x : G[s1])
                if (!(--IND[x]))
                    Q.emplace(IN[x], x);
        }
        cout << ".\n\n";
    }
}
