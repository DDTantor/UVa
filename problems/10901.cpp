#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        int side = 0, n, t, m, T = 0, in[10000], out[10000];
        cin >> n >> t >> m;
        queue<int> Q[2];
        for (int i = 0; i < m; ++i)
        {
            int a;
            string s;
            cin >> a >> s;
            in[i] = a;
            if (s == "left")
                Q[0].push(i);
            else
                Q[1].push(i);
        }
        
        while (!Q[0].empty() || !Q[1].empty())
        {
            int next = 0;
            if (Q[0].empty())
                next = in[Q[1].front()];
            else if (Q[1].empty())
                next = in[Q[0].front()];
            else
                next = min(in[Q[0].front()], in[Q[1].front()]);
            
            T = max(T, next);
            
            int cnt = 0;
            while (!Q[side].empty() && T >= in[Q[side].front()] && cnt < n)
                out[Q[side].front()] = T + t, Q[side].pop(), cnt++;
                
            side ^= 1;
            T += t;
        }
        for (int i = 0; i < m; ++i)
            cout << out[i] << '\n';
        if (c)
            cout << '\n';
    }
}
