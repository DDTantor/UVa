#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

typedef pair<int, int> state;

int s, t, c, IsPrime[1000], Prime[1000], p;
vector<int> D, V;

void SimpleSieve()
{
    IsPrime[1] = 1;

    for (int i = 2; i < 1000; ++i)
    {
        if (!IsPrime[i])
        {
            for (int j = i * i; j < 1000; j += i)
                IsPrime[j] = 1;

            Prime[p++] = i;
        }
    }
}

bool good(int st, int prime)
{
    return !(st % prime) && !V[st + prime] && st + prime <= t;
}

int solve()
{
    queue<state> Q;
    V.assign(t + 1, 0);
    Q.emplace(s, 0);
    while(!Q.empty())
    {
        int st, tm;
        tie(st, tm) = Q.front(); Q.pop();
        if (st == t)
            return tm;

        for (int i = 0; i < p && Prime[i] < st; ++i)
            if (good(st, Prime[i]))
                V[st + Prime[i]] = 1, Q.emplace(st + Prime[i], tm + 1);
    }
    return -1;
}

int main()
{
    SimpleSieve();
    while (cin >> s >> t, s || t)
        cout << "Case " << ++c << ": " << solve() << '\n';
}
