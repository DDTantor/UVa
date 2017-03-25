#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

struct Team
{
    int ID = 101, cnt = 0, p = 0, at[10] = {};
    bool sol[10] = {};
    bool operator < (const Team& B)
    {
        if (cnt != B.cnt)
            return cnt > B.cnt;
        if (p != B.p)
            return p < B.p;

        return ID < B.ID;
    }
    void Update(int pr, int t)
    {
        cnt++;
        p += t + 20 * at[pr];
        sol[pr] = true;
    }
};


int main()
{
    int t;
    cin >> t;
    cin.ignore(2);
    while (t--)
    {
        Team T[101];
        string s;
        while (getline(cin, s), !s.empty())
        {
            istringstream iss(s);
            int n, pr, time;
            char c;
            iss >> n >> pr >> time >> c;
            T[n].ID = n;
            if (c == 'I')
                T[n].at[pr]++; 
            else if (c == 'C' && !T[n].sol[pr])
                T[n].Update(pr, time);
        } 
        sort(T, T + 101);
        for (int i = 0; i < 101 && T[i].ID < 101; ++i)
            cout << T[i].ID << ' ' << T[i].cnt << ' ' << T[i].p << '\n';
        
        if (t)
            cout << '\n';
    }
}
