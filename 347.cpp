#include <iostream>
#include <cstring>

using namespace std;

int sol[9999999];

bool IsRun(int n)
{
    string s = to_string(n);
    int i = 0;
    bool P[8] = {0};
    bool D[10] = {0};
    do
    {
        if (P[i] || D[s[i] - '0'])
            return false;
        P[i] = D[s[i] - '0'] = true;
        i = (i + s[i] - '0') % s.size();
    }while(i != 0);
    for (int i = 0; i < s.size(); ++i)
        if (!P[i])
            return false;
    return true;
}

int main()
{
    int n, c = 1;
    for (int i = 9876543; i > 9; --i)
    {
        if (IsRun(i))
            sol[i] = i;
        else
            sol[i] = sol[i + 1];
    }        
    while (cin >> n, n)
        cout << "Case " <<  c++ << ": " << sol[n] << '\n';
}
