#include <iostream>
#include <queue>
#include <algorithm>
#include <list>
#include <map>

using namespace std;

typedef list<int> li;

map<li, bool> M;

bool IsPrime(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (!(n % i))
            return false;

    return true;
}

int solve(li& s)
{
    queue<pair<li, int> > Q;
    Q.emplace(s, 0);
    int t;
    while (!Q.empty())
    {
        tie(s, t) = Q.front(); Q.pop();
        if (is_sorted(s.begin(), s.end(), [](int a, int b) {return abs(a) < abs(b);}))
            return t;
        
        for (int i : s)
        {
            for (int j : s)
            {
                if (i * j < 0 && IsPrime(abs(i) + abs(j)))
                {
                    li v1, v2;
                    v1 = v2 = s;
                    v1.remove(i);
                    v2.remove(i);
                    auto pos1 = find(v1.begin(), v1.end(), j);
                    auto pos2 = find(v2.begin(), v2.end(), j);
                    pos1++;
                    v1.insert(pos1, i);
                    v1.insert(pos2, i);
                    if (!M[v1])
                        Q.emplace(v1, t + 1), M[v1] = true;

                    if (!M[v2])
                        Q.emplace(v2, t + 1), M[v2] = true;
                }
            }
        }
    }

    return -1;
}

int main()
{
    int cs = 0, a;
    while (cin >> a, a)
    {
        M.clear();
        li s;
        s.push_back(a);
        for (int i = 1; i < 8; ++i)
            cin >> a, s.push_back(a);

        cout << "Case " << ++cs << ": " << solve(s) << '\n';
    }
}
