#include <iostream>
#include <algorithm>

using namespace std;

int A[5], V[5];
bool flag;

void solve(int id, int res)
{
    if (res == 23 && id == 5)
        flag = 1;
    else if (id < 5)
    {
        for (int i = 0; i < 5; ++i)
        {
            if (!V[i])
            {
                V[i] = 1;
                solve(id + 1, res * A[i]);
                solve(id + 1, res + A[i]);
                solve(id + 1, res - A[i]);
                V[i] = 0;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    while (cin >> A[0], A[0])
    {
        for (int i = 1; i < 5; ++i)
            cin >> A[i];

        flag = false;
        for (int i = 0; i < 5; ++i)
            V[i] = 1, solve(1, A[i]), V[i] = 0;
        
              
        cout << (flag? "Possible\n" : "Impossible\n");
    }
                                      
}
