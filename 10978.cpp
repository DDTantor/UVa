#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    string C[52];
    bool B[52];
    while (cin >> n, n)
    {
        memset(B, false, sizeof(bool) * 52);
        string s1,s2;
        int p = -1;
        for (int i = 0; i < n; ++i)
        {   
            cin >> s1 >> s2;
            int s = s2.size();
            while (s)
            {
                p = (p + 1) %n;
                if (!B[p])
                    s--;
            }
            C[p] = s1;
            B[p] = true;
        }
        for (int i = 0; i < n; ++i)
        {   
            if (i)
                cout << ' ';
            cout << C[i];
        }
        cout << '\n';
    }
}
